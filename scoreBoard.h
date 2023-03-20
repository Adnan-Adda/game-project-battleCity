
// datum: 2022-12-26
// filnamn: scoreboard.h
// definition for class Scoreboard.

#ifndef BATTLE_CITY_PROJECT_SCOREBOARD_H
#define BATTLE_CITY_PROJECT_SCOREBOARD_H

#include "config.h"
#include "tank.h"
#include "textbox.h"

/// Handle and display players score, number of tanks left and the winner.
class ScoreBoard : public sf::Drawable {
private:
    std::shared_ptr<Tank> player1_;
    std::shared_ptr<Tank> player2_;
    Textbox player1_log_;
    Textbox player2_log_;
    Textbox tank_left_log_;
    Textbox winner_log_;
    int player1_score_;
    int player2_score_;
    bool isDone_;

    void setup();

    static std::string getScoreFormat(int health, int score);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    /**
     * Construct scoreboard for 2 players
     */
    ScoreBoard();

    /**
     * Add players to the scoreboard
     * @param player1
     * @param player2
     */
    void AddPlayers(std::shared_ptr<Tank> player1, std::shared_ptr<Tank> player2);

    /**
     * Update players' score and strength, also display current number of all tanks.
     * @param tankLeft
     */
    void update(size_t tankLeft);

    /**
     * increment player's score by one
     * @param player
     */
    void updateBoard(const std::shared_ptr<Tank> &player);

    /// display the winner with highest score
    void displayWinner(bool isGameOver);
};

#endif //BATTLE_CITY_PROJECT_SCOREBOARD_H
