
// datum: 2022-12-26
// filnamn: main.cpp
// Main program.

#include "game.h"

int main() {
    Game game;
    while (!game.isDone()) {
        game.handleInput();
        game.update();
        game.render();
        sf::sleep(sf::seconds(.05));
    }
    return 0;
}
