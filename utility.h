
// datum: 2022-12-26
// filnamn: utility.h
// A set of helper functions, structs and enums.

#ifndef BATTLE_CITY_PROJECT_UTILITY_H
#define BATTLE_CITY_PROJECT_UTILITY_H

#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>
#include <iostream>

enum class Direction {
    Up, Down, Right, Left, None
};

/// Construct object with two min and max.
struct Interval {
    float Min;
    float Max;

    explicit Interval(float min = 0, float max = 0) : Min(min), Max(max) {};
};

/**
 * Convert degree to radien
 * @param degree
 * @return radien
 */
float degToRad(float degree);

/**
 * Get random float. Interval's ends included.
 * @param interval
 * @return float
 */
float getRandomNum(Interval interval);

/**
 * Get random number between min and max included.
 * @param min
 * @param max
 * @return int
 */
int getRandomNum(int min, int max);

/**
 * Get the angle between object's center relative to another object's center.
 * @param fixedCenter
 * @param movingCenter
 * @return angle in degree ranges -180 to 180 degrees
 */
float getDirectionAngle(sf::Vector2f fixedCenter, sf::Vector2f movingCenter);

/**
 * Get the direction corresponding to the value returned from func getDirectionAngle.
 * The returned direction is for the moving object relative to the fixed object.
 * @param fixedObjCenter
 * @param movingObjCenter
 * @return Direction of the moving object where it faces the fixed object.
 */
Direction getRelativeDirection(sf::Vector2f fixedObjCenter, sf::Vector2f movingObjCenter);

/**
 * Construct rectangle.
 * @param centerPos
 * @param size
 * @return sf::FloatRect
 */
sf::FloatRect getBoundary(const sf::Vector2f &centerPos, const sf::Vector2f &size);

/**
 * Construct rectangle from object's position and size.
 * @tparam T must have getPosition and getSize.
 * @param obj
 * @return sf::FloatRect
 */
template<class T>
sf::FloatRect getBoundary(const T &obj) {
    return getBoundary(obj->getPosition(), obj->getSize());
}

#endif //BATTLE_CITY_PROJECT_UTILITY_H
