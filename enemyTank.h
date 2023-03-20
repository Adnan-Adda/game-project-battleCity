
// datum: 2022-12-26
// filnamn: bullet.h
// definition for class EnemyTank.

#ifndef BATTLE_CITY_PROJECT_ENEMYTANK_H
#define BATTLE_CITY_PROJECT_ENEMYTANK_H

#include "tank.h"
#include "utility.h"

/// Represent enemy tank object.
class EnemyTank : public Tank {
private:
    bullet_list_t *bullets_buffer_;
    std::shared_ptr<Tank> self_;
    Direction direction_;
    static std::vector<Direction> directions_;
    static int EnemyCount;
    const Interval DirectionTimeInterval_{0.5, 4};
    const Interval ShootTimeInterval_{1, 10};
    const Interval SpeedInterval_{0, Tank::Speed_ / 2};
    const Interval RotationTimeInterval_{0, 10};
    const Interval SpeedTimeInterval_{50.0f / Tank::TimeStepsPerSecond_, 100.0f / Tank::TimeStepsPerSecond_};

    float shoot_time_;
    float speed_time_;
    float direction_time_;
    float rotation_time_;
    float speed_;
    sf::Time direction_time_elapsed_;
    sf::Time shoot_time_elapsed_;
    sf::Time rotation_time_elapsed_;
    sf::Time speed_time_elapsed_;

    /// Change speed in random manner.
    void updateSpeed();

    /// change direction in random manner
    void updateDirection();

    /// Change rotation in random manner.
    void updateRotation();

    /// Change shooting time in random manner.
    void updateShooting();

    /// change moving time in random manner.
    void updateMove();

    /// Rest clock counter and adds the elapsed time to time members.
    void restartClock() override;

    /// Setup initial state
    void setup();

public:
    /**
     * Construct enemy with given size, strength and pointer to bullet's buffer.
     * Buffer used to store the fired bullets.
     * @param size
     * @param bulletsBuffer
     * @param strength
     */
    EnemyTank(float size, bullet_list_t *bulletsBuffer,int strength);

    /**
     * Construct enemy with given size and pointer to bullet's buffer.
     * @param size
     * @param bulletsBuffer
     */
    EnemyTank(float size, bullet_list_t *bulletsBuffer);

    /**
     * Updates enemy state. It randomize moving, shooting, rotation, and speed of the enemy.
     */
    void update() override;

    /**
     * Add pointer that points to this object.
     * Note: this must be called direct efter calling constructor.
     * @param self
     */
    void addSelf(std::shared_ptr<Tank> self);
};

#endif //BATTLE_CITY_PROJECT_ENEMYTANK_H
