#include "bullet.h"
#include "utility.h"
#include "tank.h"

Bullet::Bullet(std::shared_ptr<Tank> owner, int strength) : Destructible(strength), owner_(std::move(owner)) {
    bullet_.setRadius(Destructible::getStrength() * Radius_Ratio_);
    position_when_fired_ = owner_->getPosition();
    setOrigin(bullet_.getRadius() / 2, bullet_.getRadius() / 2);
    bullet_.setFillColor(owner_->getInnerColor());
    bullet_.setOutlineColor(owner_->getOuterColor());
    setupBulletDirection();
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= sf::Transformable::getTransform(); // get current transformation
    target.draw(bullet_, states);
}

void Bullet::update() {
    sf::Transformable::move(moving_Direction_);
}

sf::Vector2f Bullet::getSize() const {
    auto diameter = bullet_.getRadius() * 2;
    return {diameter, diameter};
}

sf::Vector2f Bullet::getPosition() const {
    return Transformable::getPosition() + position_when_fired_;
}

std::shared_ptr<Tank> Bullet::getOwner() const {
    return owner_;
}

void Bullet::setupBulletDirection() {
    float rotation = owner_->getRotation();
    float cos = std::cos(degToRad(rotation));
    float sin = std::sin(degToRad(rotation));
    auto pos = owner_->getPosition();
    float halfRadius = bullet_.getRadius() / 2;
    if (cos == 1) {
        pos.x += (owner_->getSize().x / 2) * cos;
        pos.y -= halfRadius;
    } else if (cos == -1) {
        pos.x += (owner_->getSize().x / 2) * cos - bullet_.getRadius();
        pos.y -= halfRadius;
    } else if (sin == 1) {
        pos.x -= halfRadius;
        pos.y += (owner_->getSize().x / 2) * sin;
    } else if (sin == -1) {
        pos.x -= halfRadius;
        pos.y += (owner_->getSize().x / 2) * sin - bullet_.getRadius();
    }

    bullet_.setPosition(pos);
    moving_Direction_ = {cos * Speed_, sin * Speed_};
}
