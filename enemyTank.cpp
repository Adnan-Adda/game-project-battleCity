#include "enemyTank.h"

EnemyTank::EnemyTank(float size, bullet_list_t *bulletsBuffer,int strength)
        : Tank(size, strength), bullets_buffer_(bulletsBuffer) {
    setup();
}

EnemyTank::EnemyTank(float size, bullet_list_t *bulletsBuffer) : Tank(size), bullets_buffer_(bulletsBuffer) {
    setup();
}

void EnemyTank::update() {
    updateDirection();
    updateRotation();
    updateSpeed();
    updateShooting();
    updateMove();
    restartClock();
}

int EnemyTank::EnemyCount{};
std::vector<Direction> EnemyTank::directions_{};

void EnemyTank::addSelf(std::shared_ptr<Tank> self) {
    self_ = std::move(self);
}

void EnemyTank::restartClock() {
    auto elapsed = clock_.restart();
    elapsed_ += elapsed;
    direction_time_elapsed_ += elapsed;
    shoot_time_elapsed_ += elapsed;
    rotation_time_elapsed_ += elapsed;
    speed_time_elapsed_ += elapsed;
}

void EnemyTank::updateSpeed() {
    if (speed_time_elapsed_.asSeconds() >= speed_time_) {
        speed_ = getRandomNum(SpeedInterval_);
        speed_time_ = getRandomNum(SpeedTimeInterval_);
        setSpeed(speed_);
        resetTime(speed_time_elapsed_);
    }
}

void EnemyTank::updateDirection() {
    if (direction_time_elapsed_.asSeconds() >= direction_time_) {
        direction_ = directions_[getRandomNum(0, directions_.size() - 1)];
        direction_time_ = getRandomNum(DirectionTimeInterval_);
        resetTime(direction_time_elapsed_);
    }
}

void EnemyTank::updateRotation() {
    if (rotation_time_elapsed_.asSeconds() >= rotation_time_) {
        Tank::rotateTank();
        rotation_time_ = getRandomNum(RotationTimeInterval_);
        resetTime(rotation_time_elapsed_);
    }
}

void EnemyTank::updateShooting() {
    if (shoot_time_elapsed_.asSeconds() >= shoot_time_) {
        Tank::shoot(self_, bullets_buffer_);
        shoot_time_ = getRandomNum(ShootTimeInterval_);
        resetTime(shoot_time_elapsed_);
    }
}

void EnemyTank::updateMove() {
    switch (direction_) {
        case Direction::Left:
            moveBackward();
            break;
        case Direction::Down:
            moveDownward();
            break;
        case Direction::Right:
            moveForward();
            break;
        case Direction::Up:
            moveUpward();
            break;
        default:
            break;
    }
}

void EnemyTank::setup() {
    direction_ = Direction::None;
    directions_.push_back(Direction::Down);
    directions_.push_back(Direction::Up);
    directions_.push_back(Direction::Right);
    directions_.push_back(Direction::Left);
    directions_.push_back(Direction::None);
    direction_time_ = getRandomNum(DirectionTimeInterval_);
    speed_time_ = getRandomNum(SpeedTimeInterval_);
    rotation_time_ = getRandomNum(RotationTimeInterval_);
    shoot_time_ = getRandomNum(ShootTimeInterval_);
    ++EnemyCount;
    Tank::Transformable::rotate(180);
}