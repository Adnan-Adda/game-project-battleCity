#include <complex>
#include <iostream>
#include <utility>
#include "tank.h"
#include "utility.h"

Tank::Tank(float size, int strength) : Destructible(strength) {
    setup(size);
    resetTime(elapsed_);
    speed_ = Speed_;
}

void Tank::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= sf::Transformable::getTransform();
    target.draw(body_, states);
    target.draw(head_, states);
}

void Tank::setup(float size) {
    sf::Color outerColor = sf::Color(45, 41, 38);
    sf::Color innerColor = sf::Color(233, 75, 60);

    size_ = sf::Vector2f{size, size};
    sf::Vector2f head_size = size_ * Head_To_Body_Ratio_;
    auto head_offset = sf::Vector2f{size_.x / 2, 0};
    body_.setOutlineColor(outerColor);
    body_.setFillColor(innerColor);
    head_.setFillColor(outerColor);
    body_.setSize(size_);
    body_.setOutlineThickness(OutLineThickness);
    body_.setOrigin(size_ / 2.0f);
    head_.setOrigin(head_size / 2.0f);
    head_.setSize(head_size);
    head_.setPosition(head_offset);
}

void Tank::moveForward() {
    sf::Transformable::move(speed_, 0);
}

void Tank::moveBackward() {
    sf::Transformable::move(-speed_, 0);
}

void Tank::moveUpward() {
    sf::Transformable::move(0, -speed_);
}

void Tank::moveDownward() {
    sf::Transformable::move(0, speed_);
}

void Tank::rotateTank() {
    if (elapsed_.asSeconds() >= TimeStep) {
        sf::Transformable::rotate(Rotation_Angle_);
        resetTime(elapsed_);
    }

}

void Tank::shoot(const std::shared_ptr<Tank> &owner, bullet_list_t *bulletBuffer) {
    if (elapsed_.asSeconds() >= TimeStep) {
        std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(owner);
        bulletBuffer->push_back(bullet);
        resetTime(elapsed_);
    }
}

sf::Vector2f Tank::getSize() const {
    return size_;
}

float Tank::getSpeed() const {
    return speed_;
}

void Tank::setOutLineColor(const sf::Color &color) {
    body_.setOutlineColor(color);
    head_.setFillColor(color);
}

void Tank::setInnerColor(const sf::Color &color) {
    body_.setFillColor(color);
}

sf::Color Tank::getInnerColor() const {
    return body_.getFillColor();
}

sf::Color Tank::getOuterColor() const {
    return body_.getOutlineColor();
}

void Tank::update() {
    restartClock();
}

void Tank::resetTime(sf::Time &timeObj) {
    timeObj = sf::Time::Zero;
}

void Tank::restartClock() {
    elapsed_ += clock_.restart();
}

void Tank::setSpeed(float speed) {
    speed_ = speed;
}






