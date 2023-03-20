#include "collisionHandler.h"

namespace tankCollision {
    void handleTankToTankCollision(tank_list_t &tanks) {
        for (const auto &tank: tanks)
            std::for_each(tanks.begin(), tanks.end(), TankToTankCollision(tank));
    }

    void handleTankToStoneCollision(tank_list_t &tanks, stone_list_t &stones) {
        for (const auto &tank: tanks)
            std::for_each(stones.begin(), stones.end(), TankToStoneCollision(tank));
    }

    void handleTankToWallCollision(tank_list_t &tanks, const WallBuilder &wallBuilder) {
        std::for_each(tanks.begin(), tanks.end(), TankToWallCollision(wallBuilder));
    }

    void handleBulletToTankCollision(tank_list_t &tanks, bullet_list_t &bullets, const scoreBoard_t &scoreBoard) {
        for (auto &bullet: bullets)
            std::for_each(tanks.begin(), tanks.end(), BulletToDestructibleCollision(bullet, scoreBoard));
    }

    void handleBulletToStoneCollision(stone_list_t &stones, bullet_list_t &bullets) {
        for (auto &bullet: bullets)
            std::for_each(stones.begin(), stones.end(), BulletToDestructibleCollision(bullet));
    }

    void handleBulletToWallCollision(bullet_list_t &bullets, const WallBuilder &wallBuilder) {
        std::for_each(bullets.begin(), bullets.end(), BulletToWallCollision(wallBuilder));
    }

    void handleBulletToBulletCollision(bullet_list_t &bullets) {
        for (const auto &bullet: bullets)
            std::for_each(bullets.begin(), bullets.end(), BulletToDestructibleCollision(bullet));
    }

    void clearDeadObjects(tank_list_t &tanks, stone_list_t &stones, bullet_list_t &bullets) {
        bullets.erase(std::remove_if(bullets.begin(), bullets.end(), IsDead{}), bullets.end());
        tanks.erase(std::remove_if(tanks.begin(), tanks.end(), IsDead{}), tanks.end());
        stones.erase(std::remove_if(stones.begin(), stones.end(), IsDead{}), stones.end());
    }


    void handleAllCollisions(tank_list_t &tanks, stone_list_t &stones, bullet_list_t &bullets,
                             const WallBuilder &wallBuilder, const scoreBoard_t &scoreBoard) {
        handleBulletToBulletCollision(bullets);
        handleTankToTankCollision(tanks);
        handleTankToStoneCollision(tanks, stones);
        handleTankToWallCollision(tanks, wallBuilder);
        handleBulletToTankCollision(tanks, bullets, scoreBoard);
        handleBulletToWallCollision(bullets, wallBuilder);
        handleBulletToStoneCollision(stones, bullets);
        clearDeadObjects(tanks, stones, bullets);
    }

}


