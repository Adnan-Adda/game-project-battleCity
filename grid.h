
// datum: 2022-12-26
// filnamn: frid.h
// definition for class Grid.

#ifndef BATTLE_CITY_PROJECT_GRID_H
#define BATTLE_CITY_PROJECT_GRID_H

#include <string>
#include <SFML/Graphics.hpp>
#include "utility.h"

/// Makes the available room as grid cells.
class Grid {
private:
    std::vector<sf::Vector2f> grid_;
    std::vector<int> positions_;

    void makeGrid(const sf::Vector2f &leftTopBound, const sf::Vector2f &rightBottomBound, float blockSize);

public:
    /**
     * Construct grid from the room available, each grid cell has block size.
     * @param leftTopBound
     * @param rightBottomBound
     * @param blockSize
     */
    Grid(const sf::Vector2f &leftTopBound, const sf::Vector2f &rightBottomBound, float blockSize);

    Grid() = default;

    /**
     * Get random unused position. It remove the returned position from available positions.
     * @return position
     */
    sf::Vector2f getRandomPosition();

    /**
     * Get position at specific index
     * @param index
     * @return position
     * @throw std::out_of_range
     */
    sf::Vector2f getPositionAt(int index);

    /**
     * Check whether there is available position or not
     * @return true if all positions is used otherwise false
     */
    bool isEmpty() const;

    /**
     * Get size of available positions.
     * @return size
     */
    size_t getSize() const;
};

#endif //BATTLE_CITY_PROJECT_GRID_H
