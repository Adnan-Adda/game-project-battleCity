cmake_minimum_required(VERSION 3.24)
project(battle_city_project)

set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCES *.h *.cpp)
add_executable(battle_city_project ${SOURCES} tank.h bullet.cpp bullet.h utility.cpp utility.h window.cpp window.h game.cpp game.h textbox.cpp textbox.h grid.cpp grid.h world.cpp world.h config.h wallBuilder.cpp wallBuilder.h stone.cpp stone.h collisionHandler.cpp collisionHandler.h destructible.cpp destructible.h collisionStructs.cpp collisionStructs.h scoreBoard.cpp scoreBoard.h enemyTank.cpp enemyTank.h)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(battle_city_project sfml-system sfml-window sfml-graphics sfml-audio sfml-network)