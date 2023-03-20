
// datum: 2022-12-26
// filnamn: stone.h
// definition for class Stone.

#ifndef BATTLE_CITY_PROJECT_STONE_H
#define BATTLE_CITY_PROJECT_STONE_H

#include <SFML/Graphics.hpp>
#include "utility.h"
#include "grid.h"
#include "destructible.h"

/// Represent a stone objects used as barrier in game world.
class Stone : public sf::RectangleShape, public Destructible {
private:
    const float OutLineThickness = -5;
public:
    /**
     * Construct a stone with given size, pos and strength.
     * @param blockSize
     * @param pos
     * @param strength
     */
    explicit Stone(float blockSize, const sf::Vector2f &pos, int strength = 20);

    /**
     * Set border color and inner color.
     * Note: to set different color for border/inner use setFillcolor and setOutLineColor
     * @param color
     */
    void setColor(const sf::Color &color);
};

#endif //BATTLE_CITY_PROJECT_STONE_H
