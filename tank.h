
// datum: 2022-12-26
// filnamn: tank.h
// definition for class Tank.

#ifndef BATTLE_CITY_PROJECT_TANK_H
#define BATTLE_CITY_PROJECT_TANK_H

#include <SFML/Graphics.hpp>
#include "bullet.h"

/// Concrete base class for tank.
class Tank : public sf::Transformable, public sf::Drawable, public Destructible {
protected:
    sf::Clock clock_;
    sf::Time elapsed_;
    const float TimeStepsPerSecond_ = 60.0f;
    const float Speed_ = 10.0f;

    static void resetTime(sf::Time &timeObj);

    virtual void restartClock();

private:
    float speed_;
    sf::RectangleShape body_;
    sf::RectangleShape head_;
    sf::Vector2f size_;
    const float Head_To_Body_Ratio_ = 0.2f;
    const float Rotation_Angle_ = 90;
    const float TimeStep = 20.0f / TimeStepsPerSecond_;
    const float OutLineThickness = -5;
    void setup(float size);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


public:
    /**
     * Construct tank object with given size and strength.
     * @param size
     * @param strength
     */
    explicit Tank(float size, int strength = 150);

    /// Move tank forward by speed amount
    void moveForward();

    /// Move tank backward by speed amount
    void moveBackward();

    /// Move tank upward by speed amount
    void moveUpward();

    /// Move tank downward by speed amount
    void moveDownward();

    /// Rotate tank 90 degree
    void rotateTank();

    /**
     * Fire bullet. Fired bullet added to bullet buffer. Owner is this object
     * @param owner
     * @param bulletBuffer
     */
    void shoot(const std::shared_ptr<Tank> &owner, bullet_list_t *bulletBuffer);

    /**
     * Get tank size
     * @return size
     */
    sf::Vector2f getSize() const;

    void setOutLineColor(const sf::Color &color);

    void setInnerColor(const sf::Color &color);

    float getSpeed() const;

    void setSpeed(float speed);

    sf::Color getInnerColor() const;

    sf::Color getOuterColor() const;

    virtual ~Tank() = default;

    /// Must be called. This function controls shooting and rotating time.
    virtual void update();
};

#endif //BATTLE_CITY_PROJECT_TANK_H
