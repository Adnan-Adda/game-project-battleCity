#include <iostream>
#include "grid.h"

Grid::Grid(const sf::Vector2f &leftTopBound, const sf::Vector2f &rightBottomBound, float blockSize) {
    makeGrid(leftTopBound, rightBottomBound, blockSize);
}

void Grid::makeGrid(const sf::Vector2f &leftTopBound, const sf::Vector2f &rightBottomBound, float blockSize) {
    int pos = 0;
    float halfBlock = blockSize / 2.0f;
    for (auto row = leftTopBound.x + halfBlock; row < rightBottomBound.x - halfBlock; row += blockSize) {
        for (auto col = leftTopBound.y + halfBlock; col < rightBottomBound.y - halfBlock; col += blockSize) {
            grid_.push_back({row, col});
            positions_.push_back(pos++);
        }
    }
}

sf::Vector2f Grid::getRandomPosition() {
    int index = getRandomNum(0,positions_.size()-1);
    return getPositionAt(index);
}

bool Grid::isEmpty() const {
    return positions_.empty();
}

sf::Vector2f Grid::getPositionAt(int index) {
    if(index>=grid_.size())
        throw std::out_of_range("Out of available positions");
    auto pos = *(grid_.begin() + index);
    positions_.erase(positions_.begin()+index);
    grid_.erase(grid_.begin() + index);
    return pos;
}

size_t Grid::getSize() const {
    return positions_.size();
}
