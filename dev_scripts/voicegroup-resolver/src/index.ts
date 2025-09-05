import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';
import { resolve, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { existsSync, readFileSync } from 'node:fs';

// Workspace root (assume dev_scripts/voicegroup-resolver within repo)
const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);
const repoRoot = resolve(__dirname, '../../..');

// Paths of interest
const soundDir = resolve(repoRoot, 'sound');
const voicegroupsDir = resolve(soundDir, 'voicegroups');
const directSoundDataPath = resolve(soundDir, 'direct_sound_data.inc');
const programmableWaveDataPath = resolve(soundDir, 'programmable_wave_data.inc');

type NodeKind = 'group' | 'keysplit' | 'directsound' | 'programmable' | 'square' | 'noise' | 'unknown';

type VoiceNode = {
  kind: NodeKind;
  label?: string; // for groups
  macro?: string; // original macro name
  line?: string;  // raw line
  children?: VoiceNode[]; // for groups/keysplit
  // leaf data
  sampleSymbol?: string; // DirectSoundWaveData_* or ProgrammableWaveData_*
  assetPath?: string;    // resolved .bin or .pcm path
  params?: string[];     // other params parsed
};

// Preload symbol -> asset path maps for quick resolution
function loadSymbolMap(filePath: string): Record<string, string> {
  if (!existsSync(filePath)) return {};
  const text = readFileSync(filePath, 'utf8');
  const map: Record<string, string> = {};
  // Match lines like: Label::\n  //   .incbin "path"
  const re = /(\w+)::[\s\S]*?\n\s*\.incbin\s+"([^"]+)"/g;
  let m: RegExpExecArray | null;
  while ((m = re.exec(text))) {
    const label = m[1];
    const path = m[2];
    map[label] = resolve(repoRoot, path);
  }
  return map;
}

const directSoundSymbolToAsset = loadSymbolMap(directSoundDataPath);
const programmableSymbolToAsset = loadSymbolMap(programmableWaveDataPath);

// Utility: read all lines from a file (separate file reading)
async function readLines(filePath: string): Promise<string[]> {
  const lines: string[] = [];
  const rli = createInterface({ input: createReadStream(filePath), crlfDelay: Infinity });
  for await (const raw of rli) lines.push(raw);
  return lines;
}

// Detect a referenced voicegroup label from a line, if present.
function extractVoicegroupRef(line: string): string | null {
  const m = line.match(/^\s*voice_keysplit(?:_all)?\s+([A-Za-z0-9_]+)/);
  if (!m) return null;
  const ref = m[1];
  return /^voicegroup\d{1,3}$/.test(ref) ? ref : null;
}

// Recursively read lines from a voicegroup file and any voicegroups it references via keysplit/_all.
// Returns a map from absolute filePath to its lines array.
async function readLinesRecursive(filePath: string, visited = new Set<string>()): Promise<Map<string, string[]>> {
  const out = new Map<string, string[]>();
  async function walk(fp: string) {
    if (visited.has(fp)) return;
    visited.add(fp);
    const lines = await readLines(fp);
    out.set(fp, lines);
    for (const raw of lines) {
      const ref = extractVoicegroupRef(raw);
      if (ref) {
        const childPath = voicegroupToPath(ref);
        if (existsSync(childPath)) await walk(childPath);
      }
    }
  }
  await walk(filePath);
  return out;
}

// Parse a single voice line to a VoiceNode (separate line parsing)
function parseVoiceLine(line: string): VoiceNode | null {
  const trimmed = line.trim();
  if (!trimmed || trimmed.startsWith('//') || trimmed.startsWith('@')) return null;
  if (!/^voice_\w+\b/.test(trimmed)) return null;

  const i = trimmed.indexOf(' ');
  const macro = i === -1 ? trimmed : trimmed.slice(0, i);
  const argsStr = i === -1 ? '' : trimmed.slice(i + 1).trim();
  const args = argsStr.split(',').map((s: string) => s.trim()).filter(Boolean);

  if (macro === 'voice_keysplit' || macro === 'voice_keysplit_all') {
    const targetGroup = args[0];
    return { kind: 'keysplit', macro, line: trimmed, params: args, label: targetGroup };
  }
  if (macro.startsWith('voice_directsound')) {
    const sampleSymbol = args[2];
    const assetPath = directSoundSymbolToAsset[sampleSymbol];
    return { kind: 'directsound', macro, line: trimmed, params: args, sampleSymbol, assetPath };
  }
  if (macro.startsWith('voice_programmable_wave')) {
    const sampleSymbol = args[2];
    const assetPath = programmableSymbolToAsset[sampleSymbol];
    return { kind: 'programmable', macro, line: trimmed, params: args, sampleSymbol, assetPath };
  }
  if (macro.startsWith('voice_square')) return { kind: 'square', macro, line: trimmed, params: args };
  if (macro.startsWith('voice_noise')) return { kind: 'noise', macro, line: trimmed, params: args };
  return { kind: 'unknown', macro, line: trimmed, params: args };
}

// Parse a voicegroup file into an ordered list of VoiceNode entries (1-based index matches instrument program numbers inside that group)
async function parseVoicegroupFile(filePath: string): Promise<VoiceNode[]> {
  const nodes: VoiceNode[] = [];
  const lines = await readLines(filePath);
  for (const raw of lines) {
    const labelMatch = raw.match(/^(\w+)::/);
    if (labelMatch) continue; // we infer group by filename/label elsewhere
    const node = parseVoiceLine(raw);
    if (node) nodes.push(node);
  }
  return nodes;
}

// Resolve a voicegroup label to its file path
function voicegroupToPath(label: string): string {
  // Expect labels like voicegroup164
  const m = label.match(/^voicegroup(\d{1,3})$/);
  if (!m) throw new Error(`Unsupported voicegroup label: ${label}`);
  const n = m[1].padStart(3, '0');
  return resolve(voicegroupsDir, `voicegroup${n}.inc`);
}

// Recursively resolve nodes: for keysplit nodes, we load the referenced group and attach its children
async function resolveGroup(label: string, stack: string[] = []): Promise<VoiceNode> {
  const filePath = voicegroupToPath(label);
  if (!existsSync(filePath)) throw new Error(`Voicegroup file not found for ${label}: ${filePath}`);
  if (stack.includes(label)) {
    return { kind: 'group', label, children: [{ kind: 'unknown', line: `// cycle detected for ${label}` }] };
  }
  const nextStack = [...stack, label];
  const entries = await parseVoicegroupFile(filePath);
  const children: VoiceNode[] = [];
  for (const node of entries) {
    if (node.kind === 'keysplit' && node.label) {
      // Follow into referenced voicegroup
      const sub = await resolveGroup(node.label, nextStack);
      children.push({ ...node, children: sub.children });
    } else {
      children.push(node);
    }
  }
  return { kind: 'group', label, children };
}

// JSON shape with recursive { type, samples } objects
type JsonNode = {
  type: NodeKind;
  voicegroup?: string;
  sampleSymbol?: string;
  assetPath?: string;
  params?: string[];
  samples?: JsonNode[];
};

function toJson(node: VoiceNode): JsonNode {
  const base: JsonNode = {
    type: node.kind,
    voicegroup: node.label,
    sampleSymbol: node.sampleSymbol,
    assetPath: node.assetPath,
    params: node.params,
  };
  if (node.children) base.samples = node.children.map(toJson);
  return base;
}

// Pretty-print the tree
function printTree(node: VoiceNode, indent = ''): void {
  const pad = (s: string) => indent + s;
  switch (node.kind) {
    case 'group':
      console.log(pad(`Group ${node.label}`));
      node.children?.forEach((c, i) => printTree(c, indent + '  '));
      break;
    case 'keysplit': {
      const group = node.label ?? '?';
      console.log(pad(`KeySplit -> ${group}`));
      node.children?.forEach(c => printTree(c, indent + '  '));
      break;
    }
    case 'directsound': {
      const sym = node.sampleSymbol ?? '?';
      const path = node.assetPath ?? '(unresolved)';
      console.log(pad(`DirectSound ${sym} -> ${path}`));
      break;
    }
    case 'programmable': {
      const sym = node.sampleSymbol ?? '?';
      const path = node.assetPath ?? '(unresolved)';
      console.log(pad(`Programmable ${sym} -> ${path}`));
      break;
    }
    case 'square':
      console.log(pad(`Square (${node.macro}) ${node.params?.join(', ')}`));
      break;
    case 'noise':
      console.log(pad(`Noise (${node.macro}) ${node.params?.join(', ')}`));
      break;
    default:
      console.log(pad(`Other (${node.macro}) ${node.params?.join(', ')}`));
  }
}

// CLI
async function main() {
  const [,, arg1, arg2] = process.argv;
  const argLabel = arg1 && !arg1.startsWith('-') ? arg1 : undefined;
  const modeFlag = arg2 || (arg1?.startsWith('-') ? arg1 : undefined) || '--json';
  if (!argLabel) {
    console.error('Usage: resolve-voicegroup <voicegroupNNN> [--json|--tree]');
    process.exit(1);
  }
  // Optional exploratory mode: IO-level recursive scan of referenced voicegroups
  if (modeFlag === '--scan-io') {
    const startPath = voicegroupToPath(argLabel);
    const files = await readLinesRecursive(startPath);
    const payload = Array.from(files.entries()).map(([fp, lines]) => ({ filePath: fp, lineCount: lines.length }));
    console.log(JSON.stringify({ voicegroup: argLabel, files: payload }, null, 2));
    return;
  }
  const root = await resolveGroup(argLabel);
  if (modeFlag === '--tree') {
    printTree(root);
  } else {
    const json: JsonNode = { type: 'group', voicegroup: argLabel, samples: root.children?.map(toJson) };
    console.log(JSON.stringify(json, null, 2));
  }
}

main().catch(err => {
  console.error(err);
  process.exit(1);
});
