#include <iostream>
#include "utility.h"

float degToRad(float degree) {
    return (M_PI / 180.0f) * degree;
}


int getRandomNum(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

float getRandomNum(Interval interval) {
    std::random_device rd;
    std::uniform_real_distribution<float> dist(interval.Min, interval.Max);
    return dist(rd);
}

float getDirectionAngle(sf::Vector2f fixedCenter, sf::Vector2f movingCenter) {
    sf::Vector2f diff = fixedCenter - movingCenter;
    auto angle = atan2(diff.y, diff.x) * (180 / M_PI);
    return angle;
}

Direction getRelativeDirection(sf::Vector2f fixedObjCenter, sf::Vector2f movingObjCenter) {
    auto angle = getDirectionAngle(fixedObjCenter, movingObjCenter);
    // Note the angles ranges from -180 to 180.
    if (angle > 45 && angle < 135) // Means moving object's downside faces fixed object's upper side.
        return Direction::Down;

    if (angle >= -45 && angle <= 45) // Means moving object's right side faces fixed object's left side.
        return Direction::Right;

    if (angle < -45 && angle > -135) // Means moving object's upper side faces fixed object's downside.
        return Direction::Up;

    if (angle >= 135 || angle <= -135) // Means moving object's left side faces fixed object's right side.
        return Direction::Left;

    return Direction::None;
}

sf::FloatRect getBoundary(const sf::Vector2f &centerPos, const sf::Vector2f &size) {
    sf::FloatRect rect;
    rect.left = std::abs(centerPos.x - size.x / 2);
    rect.top = std::abs(centerPos.y - size.y / 2);
    rect.width = size.x;
    rect.height = size.y;
    return rect;
}




