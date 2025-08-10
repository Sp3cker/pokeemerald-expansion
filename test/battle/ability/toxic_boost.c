#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Toxic Boost causes poison to boost Attack by 50%", s16 damage)
{
    u8 poisoned;
    PARAMETRIZE { poisoned = 0; }
    PARAMETRIZE { poisoned = 1; }
    PARAMETRIZE { poisoned = 2; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_FLAREON)
        {
            if (poisoned == 1)
                Status1(STATUS1_POISON);
            if (poisoned == 2)
                Status1(STATUS1_TOXIC_POISON);
            Ability(ABILITY_TOXIC_BOOST);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[2].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Toxic Boost prevents damage from (Toxic) Poison")
{
    u8 status;
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }

    GIVEN {
        PLAYER(SPECIES_FLAREON) { Ability(ABILITY_TOXIC_BOOST); Status1(status);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPLASH); }
    } SCENE {
        NOT HP_BAR(player);

    }
}
