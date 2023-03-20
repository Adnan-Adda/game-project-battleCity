#include <iostream>
#include "world.h"

namespace world {

    tank_list_t makeEnemies(Grid &grid, size_t N, float blockSize, bullet_list_t *bulletsBuffer) {
        tank_list_t enemies;
        while (N && !grid.isEmpty()) {
            auto pos = grid.getRandomPosition();
            auto enemy = std::make_shared<EnemyTank>(blockSize, bulletsBuffer);
            enemy->addSelf(enemy);
            enemies.push_back(enemy);
            enemies.back()->setPosition(pos);
            --N;
        }
        return enemies;
    }

    stone_list_t buildBarriers(Grid &grid, float blockSize, int n_hard, int n_weak) {
        const sf::Color HardStoneColor = sf::Color(128, 128, 128);
        stone_list_t barriers;
        while (n_weak && !grid.isEmpty()) {
            auto pos = grid.getRandomPosition();
            barriers.push_back(std::make_shared<Stone>(blockSize, pos));
            --n_weak;
        }
        while (n_hard && !grid.isEmpty()) {
            auto pos = grid.getRandomPosition();
            auto stone = std::make_shared<Stone>(blockSize, pos, HardStone);
            stone->setColor(HardStoneColor);
            barriers.push_back(stone);
            --n_hard;
        }
        return barriers;
    }
}

