#include "scoreBoard.h"


ScoreBoard::ScoreBoard() : player1_score_(0), player2_score_(0), isDone_(false) {
    setup();
}

void ScoreBoard::setup() {

    const float Border = 5.0f;
    const float PlayerBoxWidth = (config::WindowWidth * 0.8) / 2;
    const float EnemyBoxWidth = config::WindowWidth * 0.2f;
    const float BoxHeight = config::PanelHeight - Border * 2;
    const float margin = 10;
    player1_log_.setBoxSize({PlayerBoxWidth, BoxHeight});
    player1_log_.setPosition(Border, Border);
    player1_log_.setBorderBoxStyle(sf::Color::Black, Border);
    player1_log_.setMargin(margin);

    tank_left_log_.setBorderBoxStyle(sf::Color::Red, Border);
    tank_left_log_.setBoxSize({EnemyBoxWidth, BoxHeight});
    tank_left_log_.setPosition(PlayerBoxWidth + Border * 3, Border);
    tank_left_log_.setMargin(margin);

    player2_log_.setBoxSize({PlayerBoxWidth - Border, BoxHeight});
    player2_log_.setPosition(PlayerBoxWidth + EnemyBoxWidth + Border * 5, Border);
    player2_log_.setBorderBoxStyle(sf::Color::Black, Border);
    player2_log_.setMargin(margin);

    winner_log_.setBoxSize(config::WindowSize / 4.0f);
    winner_log_.setPosition(config::WindowSize / 4.0f);
    winner_log_.setMargin(100);
    winner_log_.fillBackgroundColor(sf::Color::Magenta);
    winner_log_.setBorderBoxStyle(sf::Color::Green, -20);
}

void ScoreBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(player1_log_);
    target.draw(player2_log_);
    target.draw(tank_left_log_);
    if (isDone_)
        target.draw(winner_log_);
}

void ScoreBoard::AddPlayers(std::shared_ptr<Tank> player1, std::shared_ptr<Tank> player2) {
    player1_ = std::move(player1);
    player2_ = std::move(player2);
    player1_log_.setBorderColor(player1_->getInnerColor());
    player2_log_.setBorderColor(player2_->getInnerColor());
}

void ScoreBoard::update(size_t tankLeft) {
    if (player1_->isDead())
        player1_log_.fillBackgroundColor(sf::Color::Red);
    else
        player1_log_.setString(getScoreFormat(player1_->getStrength(), player1_score_));

    if (player2_->isDead())
        player2_log_.fillBackgroundColor(sf::Color::Red);
    else
        player2_log_.setString(getScoreFormat(player2_->getStrength(), player2_score_));
    tank_left_log_.setString("Tank Left: " + std::to_string(tankLeft));
}

void ScoreBoard::updateBoard(const std::shared_ptr<Tank> &player) {
    if (player == player1_)
        ++player1_score_;
    if (player == player2_)
        ++player2_score_;
}

std::string ScoreBoard::getScoreFormat(int health, int score) {
    return std::string("Health: " + std::to_string(health) + "\tScore: " + std::to_string(score));
}

void ScoreBoard::displayWinner(bool isGameOver) {
    if (isGameOver) {
        isDone_ = isGameOver;
        if (player1_score_ > player2_score_)
            winner_log_.setString("Winner player 1\n Score " + std::to_string(player1_score_));
        else if (player2_score_ > player1_score_)
            winner_log_.setString("Winner player 2\n Score " + std::to_string(player2_score_));
        else
            winner_log_.setString("No winner");
    }
}


