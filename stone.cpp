#include "stone.h"

Stone::Stone(float blockSize, const sf::Vector2f &pos, int strength) : Destructible(strength) {
    sf::Color defaultColor = sf::Color(139, 69, 19);
    sf::RectangleShape::setSize({blockSize, blockSize});
    sf::RectangleShape::setOutlineThickness(OutLineThickness);
    sf::RectangleShape::setOrigin(blockSize / 2, blockSize / 2);
    sf::RectangleShape::setPosition(pos);
    setColor(defaultColor);
}

void Stone::setColor(const sf::Color &color) {
    sf::RectangleShape::setFillColor(color);
    sf::RectangleShape::setOutlineColor(color);
}