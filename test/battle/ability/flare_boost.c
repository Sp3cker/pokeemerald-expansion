#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flare Boost causes burn to boost Sp. Attack by 50%", s16 damage)
{
    bool8 burned;
    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_HYPER_VOICE].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_DRIFBLIM)
        {
            if (burned == TRUE)
                Status1(STATUS1_BURN);
            Ability(ABILITY_FLARE_BOOST);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Flare Boost does not prevent burn from lowering Attack by 50%", s16 damage)
{
    bool8 burned;
    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_DRIFBLIM)
        {
            if (burned == TRUE)
                Status1(STATUS1_BURN);
            Ability(ABILITY_FLARE_BOOST);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Flare Boost prevents damage from burn")
{
    GIVEN {
        PLAYER(SPECIES_FLAREON) { Ability(ABILITY_FLARE_BOOST); Status1(STATUS1_BURN);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPLASH); }
    } SCENE {
        NOT HP_BAR(player);

    }
}
