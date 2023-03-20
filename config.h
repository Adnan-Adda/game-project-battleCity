
// datum: 2022-12-26
// filnamn: config.h
// A set of const used for game configurations

#ifndef BATTLE_CITY_PROJECT_CONFIG_H
#define BATTLE_CITY_PROJECT_CONFIG_H

#include <SFML/Graphics.hpp>

namespace config {
    const float WallThickness = 20.0f;
    const float PanelHeight = 60.0f;
    const sf::Uint32 MaxWindowWidth = 1920;
    const sf::Uint32 MaxWindowHeight = 1080;
    const sf::Uint32 WindowHeight = std::min(sf::VideoMode::getDesktopMode().height, MaxWindowHeight);
    const sf::Uint32 WindowWidth = std::min(sf::VideoMode::getDesktopMode().width, MaxWindowWidth);
    const sf::Vector2f WindowSize = {static_cast<float>(WindowWidth), static_cast<float>(WindowHeight)};
    const sf::Vector2f LeftTopBound = {WallThickness, WallThickness + PanelHeight};
    const sf::Vector2f RightBottomBound = {WindowWidth - WallThickness * 2, WindowHeight - WallThickness - PanelHeight};
}
#endif //BATTLE_CITY_PROJECT_CONFIG_H
