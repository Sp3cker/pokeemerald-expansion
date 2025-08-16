#ifndef GUARD_POKEDEX_PLUS_HGSS_H
#define GUARD_POKEDEX_PLUS_HGSS_H

void CB2_OpenPokedexPlusHGSS(void);
void CB2_OpenPokedexPlusHGSSToInfo(void);
// void SetPokedexDirectSpecies(u16 species);
extern u16 gDirectToInfoScreenPokemon;
u16 GetLastSelectedPokemon();
void Task_DisplayCaughtMonDexPageHGSS(u8);

#endif // GUARD_POKEDEX_PLUS_HGSS_H
