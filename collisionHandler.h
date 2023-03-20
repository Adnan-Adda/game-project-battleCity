
// datum: 2022-12-26
// filnamn: collisionHandler.h
// A set of function used to handle collisions

#ifndef BATTLE_CITY_PROJECT_COLLISIONHANDLER_H
#define BATTLE_CITY_PROJECT_COLLISIONHANDLER_H

#include "collisionStructs.h"

namespace tankCollision {

    /**
     * Checks and adjust tank's position on tank to tank collision, also updates tank strength.
     * @param tanks
     */
    void handleTankToTankCollision(tank_list_t &tanks);

    /**
     * Checks and adjust tank's position on tank to stone collision.
     * @param tanks
     * @param stones
     */
    void handleTankToStoneCollision(tank_list_t &tanks, stone_list_t &stones);

    /**
     * Checks and adjust tank's position on tank to wall collision.
     * @param tanks
     * @param wallBuilder
     */
    void handleTankToWallCollision(tank_list_t &tanks, const WallBuilder &wallBuilder);

    /**
     * Checks and updates tank's and bullet's strength on bullet to tank collision. Also updates player score
     * @param tanks
     * @param bullets
     * @param scoreBoard
     */
    void handleBulletToTankCollision(tank_list_t &tanks, bullet_list_t &bullets, const scoreBoard_t &scoreBoard);

    /**
     * Checks and destroy bullet on bullet to wall collision.
     * @param bullets
     * @param wallBuilder
     */
    void handleBulletToWallCollision(bullet_list_t &bullets, const WallBuilder &wallBuilder);

    /**
     * Checks and updates stone's and bullet's strength on bullet to stone collision.
     * @param stones
     * @param bullets
     */
    void handleBulletToStoneCollision(stone_list_t &stones, bullet_list_t &bullets);

    /**
     * Checks and updates bullet's strength on bullet to bullet collision.
     * @param bullets
     */
    void handleBulletToBulletCollision(bullet_list_t &bullets);

    /**
     * Remove all dead or destroyed objects from lists.
     * @param tanks
     * @param stones
     * @param bullets
     */
    void clearDeadObjects(tank_list_t &tanks, stone_list_t &stones, bullet_list_t &bullets);

    /**
     * Calls all functions that handle collisions.
     * @param tanks
     * @param stones
     * @param bullets
     * @param wallBuilder
     * @param scoreBoard
     */
    void handleAllCollisions(tank_list_t &tanks, stone_list_t &stones, bullet_list_t &bullets,
                             const WallBuilder &wallBuilder, const scoreBoard_t &scoreBoard);
}

#endif //BATTLE_CITY_PROJECT_COLLISIONHANDLER_H
