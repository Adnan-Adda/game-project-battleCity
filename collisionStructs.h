
// datum: 2022-12-26
// filnamn: collisionStructs.h
// A set of structs used as functor to handle collisions

#ifndef BATTLE_CITY_PROJECT_COLLISIONSTRUCTS_H
#define BATTLE_CITY_PROJECT_COLLISIONSTRUCTS_H


#include "tank.h"
#include "config.h"
#include "utility.h"
#include "wallBuilder.h"
#include "stone.h"
#include "scoreBoard.h"


using tank_list_t = std::vector<std::shared_ptr<Tank>>;
using stone_list_t = std::vector<std::shared_ptr<Stone>>;
using bullet_list_t = std::vector<std::shared_ptr<Bullet>>;
using tank_t = std::shared_ptr<Tank>;
using stone_t = std::shared_ptr<Stone>;
using bullet_t = std::shared_ptr<Bullet>;
using scoreBoard_t = std::shared_ptr<ScoreBoard>;


namespace tankCollision {
    ///The amount to be subtracted from tanks on collision with each other
    const int CollisionStrengthTankToTank = 1;


    /// Functor to handle tank to tank collision
    struct TankToTankCollision {
    private:
        tank_t tank_;
    public:
        /**
         * @brief Construct with tank object to be checked against other tanks
         * @param tank
         */
        explicit TankToTankCollision(tank_t tank);

        /**
         * Call with tank object to handle collision and adjust tank position on collision and decrease tanks' strength
         * by amount defined in CollisionStrengthTankToTank.
         * @param tank to be checked against member tank
         */
        void operator()(const tank_t &tank);
    };

    /// Functor to handle tank to stone collision
    struct TankToStoneCollision {
    private:
        tank_t tank_;
    public:
        /**
         * Construct with tank object to be checked against other stone objects
         * @param tank
         */
        explicit TankToStoneCollision(tank_t tank);

        /**
         * Call with stone object to handle collision and adjust tank position on collision and decrease tanks' strength
         * and stone's strength.
         * @param stone
         */
        void operator()(const stone_t &stone);
    };

    /// Functor to handle tank to wall collision
    struct TankToWallCollision {
    private:
        WallBuilder wallBuilder_;
    public:
        /**
         * Construct with wallBuilder object to be used to check tank collision with walls.
         * @param wallBuilder
         */
        explicit TankToWallCollision(WallBuilder wallBuilder);

        /**
         * Call with tank object to adjust tank position on collision with walls
         * @param tank
         */
        void operator()(const tank_t &tank);
    };


    /// Functor to handle Bullet to wall collision
    struct BulletToWallCollision {
    private:
        WallBuilder wallBuilder_;
    public:
        /**
         * Construct with wallBuilder object to be used to check bullet collision with walls.
         * @param wallBuilder
         */
        explicit BulletToWallCollision(WallBuilder wallBuilder);

        /**
         * Call with bullet object to check for bullet collisions with walls
         * and mark bullet as dead if there is collision.
         * @param bullet
         */
        void operator()(const bullet_t &bullet);
    };

    /// Functor to check whether Destructible is dead or not
    struct IsDead {
        /**
         * Checks whether destructible object is dead or not.
         * @param destructible
         * @return true if destructible is dead or its use count is 0 otherwise false.
         */
        bool operator()(const std::shared_ptr<Destructible> &destructible) const;
    };

    /**
     * Function template to check bullet to destructible collision,
     * if there is collision decrease the strength of both objects.
     * @tparam T Must be transformable and has getSize()
     * @param bullet
     * @param destructible
     * @return true if there is collision otherwise false.
     */
    template<class T>
    bool BulletToDestructibleCollisionFunc(const bullet_t &bullet, const std::shared_ptr<T> &destructible) {
        if (getBoundary(destructible).intersects(getBoundary(bullet))) {
            auto damage = destructible->getStrength();
            destructible->decreaseStrength(bullet->getStrength());
            bullet->decreaseStrength(damage);
            return true;
        }
        return false;
    }

    /// Functor to handle bullet to Destructible collision
    struct BulletToDestructibleCollision {
    private:
        bullet_t bullet_;
        std::shared_ptr<ScoreBoard> score_board_;
    public:

        /**
         * Construct with bullet object to be checked and scoreboard to be used to update player score.
         * @param bullet
         * @param scoreBoard default nullptr
         */
        explicit BulletToDestructibleCollision(bullet_t bullet, std::shared_ptr<ScoreBoard> scoreBoard = nullptr);

        /**
         * Call with tank object to check for bullet to tank collisions, update player score and object strength.
         * @param tank
         */
        void operator()(const tank_t &tank);

        /**
         * Call with stone object to check for bullet to stone collisions, update object strength and bullet strength.
         * @param stone
         */
        void operator()(const stone_t &stone);

        /**
         * Call with bullet object to check for bullet to bullet collisions, update bullet strength.
         * @param bullet
         */
        void operator()(const bullet_t &bullet);
    };

    /**
     * Translate tank position by the amount of intersection between tank and object collided by tank.
     * @param tank
     * @param direction
     * @param intersection
     */
    void adjustTankPosition(const tank_t &tank, const Direction &direction, const sf::FloatRect &intersection);

}

#endif //BATTLE_CITY_PROJECT_COLLISIONSTRUCTS_H
