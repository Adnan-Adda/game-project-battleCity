
// datum: 2022-12-26
// filnamn: bullet.h
// definition for class Bullet.

#ifndef BATTLE_CITY_PROJECT_BULLET_H
#define BATTLE_CITY_PROJECT_BULLET_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "destructible.h"

class Tank;

/// Represent a bullet object that can be fired by a tank.
class Bullet : public sf::Transformable, public sf::Drawable, public Destructible {
private:
    const float Speed_ = 30.0f;
    const float Radius_Ratio_ = 0.25f;
    sf::Vector2f moving_Direction_;
    sf::CircleShape bullet_;
    std::shared_ptr<Tank> owner_;
    sf::Vector2f position_when_fired_;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    /**
     * Setup bullet direction relative to its owner. Places the bullet in front of Tank's head
     */
    void setupBulletDirection();

public:
    /**
     * Construct Bullet object with owner who fired the bullet and  bullet's strength/power
     * @param owner who fired the bullet
     * @param strength bullet's strength/power default 20 unit
     */
    explicit Bullet(std::shared_ptr<Tank> owner, int strength = 20);

    /**
     * Get bullet size as {bullet's diameter, bullet's diameter}
     * @return bullet size
     */
    sf::Vector2f getSize() const;

    /**
     * Move bullets by speed unit efter it fired, must calls repeatedly
     */
    void update();

    /**
     * Get current bullet position
     * @return position
     */
    sf::Vector2f getPosition() const;

    /**
     * Get bullet owner
     * @return owner as shared_ptr
     */
    std::shared_ptr<Tank> getOwner() const;

};

using bullet_list_t = std::vector<std::shared_ptr<Bullet>>;
#endif //BATTLE_CITY_PROJECT_BULLET_H
