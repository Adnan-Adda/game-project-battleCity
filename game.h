
// datum: 2022-12-26
// filnamn: game.h
// definition for class game.

#ifndef BATTLE_CITY_PROJECT_GAME_H
#define BATTLE_CITY_PROJECT_GAME_H

#include "window.h"
#include "world.h"

/// Responsible for handling input events, updating game state, rendering objects on screen and displaying winner.
class Game {
private:
    WallBuilder wallBuilder_;
    std::unique_ptr<Window> window_;
    Grid grid_;
    stone_list_t stones_;
    std::shared_ptr<Tank> player1_;
    std::shared_ptr<Tank> player2_;
    scoreBoard_t scoreBoard_;
    std::vector<std::shared_ptr<Tank>> tanks_;
    std::vector<std::shared_ptr<Bullet>> bullets_;

    const std::string Title = "Battle City";
    const float BlockSize = 50.0f;
    const int N_Enemy = 20;
    const int N_HardStone = 100;
    const int N_WeakStone = 100;

    /// Maps keyboard keys with player one. Player on on left side
    void playerLeftSideInputControls(tank_t &player);

    /// Maps keyboard keys with player two. Player two on right side
    void playerRightSideInputControls(tank_t &player);

    /// Setup players positions and color.
    void setupPlayers();

    /// True if both players is dead or all enemy's is dead, otherwise false.
    bool isGameOver();

public:

    /// Construct game object.
    Game();

    /// Handle input keyboard events.
    void handleInput();

    /// calls all game object's update methods.
    void update();

    /// Render objects on screen.
    void render();

    /**
     * Checks for window poll events related to close window.
     * @return true if window key event is pressed otherwise false.
     */
    bool isDone() const;

};

#endif //BATTLE_CITY_PROJECT_GAME_H
