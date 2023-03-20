
// datum: 2022-12-26
// filnamn: wallBuilder.h
// definition for class WallBuilder.

#ifndef BATTLE_CITY_PROJECT_WALLBUILDER_H
#define BATTLE_CITY_PROJECT_WALLBUILDER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "utility.h"
#include "grid.h"

/// Represent a wall's object around the window.
class WallBuilder {
private:
    std::vector<sf::RectangleShape> walls_;
    float right_boundary_;
    float left_boundary_;
    float top_boundary_;
    float bottom_boundary_;
    float wall_thickness_;
public:
    //WallBuilder(const sf::Vector2f &windowSize, float topOffset, float thickness);

    /**
     * Get the constructed walls.
     * @return walls
     */
    [[nodiscard]] const std::vector<sf::RectangleShape> &getWalls() const;

    /**
     * Build walls at edges of the window
     * @param windowSize
     * @param topOffset
     * @param thickness
     */
    void buildWalls(const sf::Vector2f &windowSize, float topOffset, float thickness);

    /// Get X coordinate at left side. This gives the start of the room from left.
    float getLeftBoundary() const;

    /// Get X coordinate at right side. This gives the end of the room from right.
    float getRightBoundary() const;

    /// Get Y coordinate from top side. This gives the start of the room from top.
    float getTopBoundary() const;

    /// Get Y coordinate at bottom side. This gives the end of the room at bottom.
    float getBottomBoundary() const;

    float getWallThickness() const;

    void setColor(const sf::Color &color);
};

sf::RectangleShape createRectangle(const sf::Vector2f &size, const sf::Vector2f &pos);

#endif //BATTLE_CITY_PROJECT_WALLBUILDER_H
