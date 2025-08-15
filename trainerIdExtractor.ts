import { promises as fs } from "node:fs";

// deno-lint-ignore-file
// If editing in a non-Deno TS environment, declare Deno to silence diagnostics.
// This has no effect at runtime in Deno.
// eslint-disable-next-line @typescript-eslint/no-explicit-any
declare const Deno: any;

type SectorInfo = {
  id: number;
  checksum: number;
  signature: number;
  counter: number;
  validSignature: boolean;
  raw: Uint8Array;
};

const CHUNK_SIZE = 0x1000; // 4096
const TOTAL_SIZE = 0x20000; // 131072
const MGBA_SIZE = 0x20010; // 131088
const NUM_CHUNKS = 32;
const SIGNATURE = 0x08012025;
const SECTOR_DATA_SIZE = 0x0ff4; // 4084
const VARS_START = 0x4000;
const VARS_BASE_IN_SB1 = 0x139C; // from include/global.h
const VAR_RANDOMIZER_MODE = 0x4052;

function splitSaveIntoChunks(buf: Uint8Array): SectorInfo[] {
  let u8 = buf;
  if (u8.byteLength === MGBA_SIZE) u8 = u8.subarray(0, TOTAL_SIZE);
  if (u8.byteLength < TOTAL_SIZE) throw new Error("Save must be at least 128KB");

  const chunks: SectorInfo[] = [];
  for (let i = 0; i < NUM_CHUNKS; i++) {
    const start = i * CHUNK_SIZE;
    const raw = u8.subarray(start, start + CHUNK_SIZE);
    const id = raw[4084] | (raw[4085] << 8);
    const checksum = raw[4086] | (raw[4087] << 8);
    const signature =
      raw[4088] | (raw[4089] << 8) | (raw[4090] << 16) | (raw[4091] << 24);
    const counter =
      raw[4092] | (raw[4093] << 8) | (raw[4094] << 16) | (raw[4095] << 24);
    chunks.push({
      id,
      checksum,
      signature,
      counter,
      validSignature: signature === SIGNATURE,
      raw,
    });
  }
  return chunks;
}

function getLatestValidSectorById(sectors: SectorInfo[], logicalId: number) {
  const cands = sectors.filter((s) => s.validSignature && s.id === logicalId);
  if (!cands.length) return undefined;
  return cands.reduce((a, b) => (b.counter > a.counter ? b : a));
}

function getSectorByIdAndCounter(
  sectors: SectorInfo[],
  logicalId: number,
  counter: number,
) {
  return sectors.find(
    (s) => s.validSignature && s.id === logicalId && s.counter === counter,
  );
}

function reconstructSaveBlock1(
  sectors: SectorInfo[],
  counter: number,
  minLength: number,
) {
  const out = new Uint8Array(Math.max(minLength, SECTOR_DATA_SIZE * 16));
  for (let lid = 1; lid <= 16; lid++) {
    const sec = getSectorByIdAndCounter(sectors, lid, counter);
    if (!sec) continue;
    const start = (lid - 1) * SECTOR_DATA_SIZE;
    out.set(sec.raw.subarray(0, SECTOR_DATA_SIZE), start);
  }
  return out;
}

export function readRandomizerModeFromSectors(sectors: SectorInfo[]): number {
  const latestSav2 = getLatestValidSectorById(sectors, 0);
  if (!latestSav2) throw new Error("No valid logical id 0 (SaveBlock2)");
  const counter = latestSav2.counter;

  const varIndex = VAR_RANDOMIZER_MODE - VARS_START; // 0x52
  const byteOffset = VARS_BASE_IN_SB1 + varIndex * 2; // 0x1440
  const sb1 = reconstructSaveBlock1(sectors, counter, byteOffset + 2);

  return sb1[byteOffset] | (sb1[byteOffset + 1] << 8);
}

export async function readRandomizerModeFromFile(path: string): Promise<number> {
  const data = await fs.readFile(path);
  const sectors = splitSaveIntoChunks(new Uint8Array(data.buffer, data.byteOffset, data.byteLength));
  return readRandomizerModeFromSectors(sectors);
}
