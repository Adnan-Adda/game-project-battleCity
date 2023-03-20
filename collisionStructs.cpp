#include "collisionStructs.h"

#include <utility>

namespace tankCollision {

    //===============================TankToTankCollision Functor======================================

    TankToTankCollision::TankToTankCollision(tank_t tank) : tank_(std::move(tank)) {
    }

    void TankToTankCollision::operator()(const tank_t &tank) {
        if (tank_ == tank)
            return;
        sf::FloatRect intersection;
        if (getBoundary(tank_).intersects(getBoundary(tank), intersection)) {
            Direction DirectionTankX = getRelativeDirection(tank->getPosition(), tank_->getPosition());
            Direction DirectionTankY = getRelativeDirection(tank_->getPosition(), tank->getPosition());
            adjustTankPosition(tank_, DirectionTankX, intersection);
            adjustTankPosition(tank, DirectionTankY, intersection);
            tank->decreaseStrength(CollisionStrengthTankToTank);
            tank_->decreaseStrength(CollisionStrengthTankToTank);
        }
    }

//===============================TankToStoneCollision Functor======================================

    TankToStoneCollision::TankToStoneCollision(tank_t tank) : tank_(std::move(tank)) {
    }

    void TankToStoneCollision::operator()(const stone_t &stone) {
        sf::FloatRect intersection;
        if (getBoundary(stone).intersects(getBoundary(tank_), intersection)) {
            Direction direction = getRelativeDirection(stone->getPosition(), tank_->getPosition());
            adjustTankPosition(tank_, direction, intersection);
        }
    }

//===============================TankToWallCollision Functor======================================

    TankToWallCollision::TankToWallCollision(WallBuilder wallBuilder) : wallBuilder_(std::move(wallBuilder)) {
    }

    void TankToWallCollision::operator()(const tank_t &tank) {
        auto tankPos = tank->getPosition();
        auto offset = wallBuilder_.getWallThickness();
        auto shiftDistance = offset / 2;
        if (tankPos.x - offset < wallBuilder_.getLeftBoundary()) //left collision
            tank->setPosition(tankPos.x + shiftDistance, tankPos.y);
        else if (tankPos.x + offset > wallBuilder_.getRightBoundary()) //right collision
            tank->setPosition(tankPos.x - shiftDistance, tankPos.y);
        else if (tankPos.y - offset < wallBuilder_.getTopBoundary()) //top collision
            tank->setPosition(tankPos.x, tankPos.y + shiftDistance);
        else if (tankPos.y + offset > wallBuilder_.getBottomBoundary()) //bottom collision
            tank->setPosition(tankPos.x, tankPos.y - shiftDistance);
    }

//===============================BulletToWallCollision Functor======================================

    BulletToWallCollision::BulletToWallCollision(WallBuilder wallBuilder) : wallBuilder_(std::move(wallBuilder)) {

    }

    void BulletToWallCollision::operator()(const bullet_t &bullet) {
        auto currentPos = bullet->getPosition();
        auto offset = wallBuilder_.getWallThickness();
        if (currentPos.x + offset >= wallBuilder_.getRightBoundary() ||
            currentPos.y + offset >= wallBuilder_.getBottomBoundary() ||
            currentPos.y - offset <= wallBuilder_.getTopBoundary() ||
            currentPos.x - offset <= wallBuilder_.getLeftBoundary()) {
            bullet->decreaseStrength(bullet->getStrength());
        }
    }

//===============================IsDead Functor======================================

    bool IsDead::operator()(const std::shared_ptr<Destructible> &destructible) const {
        return destructible.use_count() == 0 || destructible->isDead();
    }

//===============================BulletToDestructibleCollision Functor======================================

    BulletToDestructibleCollision::BulletToDestructibleCollision(bullet_t bullet,
                                                                 std::shared_ptr<ScoreBoard> scoreBoard)
            : bullet_(std::move(bullet)), score_board_(std::move(scoreBoard)) {
    }

    void BulletToDestructibleCollision::operator()(const tank_t &tank) {
        if (bullet_->getOwner() == tank)
            return;
        BulletToDestructibleCollisionFunc(bullet_, tank);
        if (BulletToDestructibleCollisionFunc(bullet_, tank) && score_board_) {
            score_board_->updateBoard(bullet_->getOwner());
        }
    }

    void BulletToDestructibleCollision::operator()(const stone_t &stone) {
        BulletToDestructibleCollisionFunc(bullet_, stone);
    }

    void BulletToDestructibleCollision::operator()(const bullet_t &bullet) {
        if (bullet == bullet_)
            return;
        BulletToDestructibleCollisionFunc(bullet_, bullet);
    }

//===============================Helper functions======================================

    void adjustTankPosition(const tank_t &tank, const Direction &direction, const sf::FloatRect &intersection) {
        auto currentPos = tank->getPosition();
        switch (direction) {
            case Direction::Left:
                tank->setPosition(currentPos.x + intersection.width, currentPos.y);
                break;
            case Direction::Down:
                tank->setPosition(currentPos.x, currentPos.y - intersection.height);
                break;
            case Direction::Up:
                tank->setPosition(currentPos.x, currentPos.y + intersection.height);
                break;
            case Direction::Right:
                tank->setPosition(currentPos.x - intersection.width, currentPos.y);
                break;
            default:
                break;
        }
    }
}
