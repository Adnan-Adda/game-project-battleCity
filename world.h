
// datum: 2022-12-26
// filnamn: world.h
// A set of function to build game's world

#ifndef BATTLE_CITY_PROJECT_WORLD_H
#define BATTLE_CITY_PROJECT_WORLD_H
#include "enemyTank.h"
#include "collisionHandler.h"

namespace world {
    /// Strength value for hard stone
    const int HardStone = 100;

    /// Generate enemies.
    tank_list_t makeEnemies(Grid &grid, size_t N, float blockSize, bullet_list_t *bulletsBuffer);

    /// Generate stones.
    stone_list_t buildBarriers(Grid &grid, float blockSize, int n_hard, int n_weak);
}

#endif //BATTLE_CITY_PROJECT_WORLD_H
