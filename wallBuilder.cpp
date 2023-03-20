#include "wallBuilder.h"

const  std::vector<sf::RectangleShape> &WallBuilder::getWalls() const {
    return walls_;
}

void WallBuilder::setColor(const sf::Color &color) {
    for(auto& wall : walls_)
        wall.setFillColor(color);
}

float WallBuilder::getLeftBoundary() const {
    return left_boundary_;
}

float WallBuilder::getRightBoundary() const {
    return right_boundary_;
}

float WallBuilder::getTopBoundary() const {
    return top_boundary_;
}

float WallBuilder::getBottomBoundary() const {
    return bottom_boundary_;
}

void WallBuilder::buildWalls(const sf::Vector2f &windowSize, float topOffset, float thickness) {
    sf::Vector2f size = sf::Vector2f{windowSize.x, thickness};
    float pos_left = 0;
    left_boundary_ = thickness;
    top_boundary_ = topOffset + thickness;
    right_boundary_ = windowSize.x - thickness;
    bottom_boundary_= windowSize.y - thickness;
    wall_thickness_ = thickness;
    walls_.push_back(createRectangle(size, {pos_left, topOffset})); // Top
    walls_.push_back(createRectangle(size, {pos_left, bottom_boundary_})); //bottom
    walls_.push_back(createRectangle({size.y, size.x}, {pos_left, topOffset})); //left
    walls_.push_back(createRectangle({size.y, size.x}, {right_boundary_, topOffset})); // right
    setColor(sf::Color(96,96,96));
}

float WallBuilder::getWallThickness() const {
    return wall_thickness_;
}


sf::RectangleShape createRectangle(const sf::Vector2f &size, const sf::Vector2f &pos) {
    sf::RectangleShape rectangleShape(size);
    rectangleShape.setPosition(pos);
    return rectangleShape;
};