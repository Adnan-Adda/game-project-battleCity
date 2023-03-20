#include <iostream>
#include "game.h"

Game::Game() {
    wallBuilder_.buildWalls(config::WindowSize, config::PanelHeight, config::WallThickness);
    window_ = std::make_unique<Window>(Title, sf::Vector2u{config::WindowWidth, config::WindowHeight});
    grid_ = std::move(Grid{config::LeftTopBound, config::RightBottomBound, BlockSize});
    scoreBoard_ = std::make_shared<ScoreBoard>();
    setupPlayers();
    auto enemies = world::makeEnemies(grid_, N_Enemy, BlockSize, &bullets_);
    stones_ = world::buildBarriers(grid_, BlockSize, N_HardStone, N_WeakStone);
    tanks_.insert(tanks_.end(), std::make_move_iterator(enemies.begin()), std::make_move_iterator(enemies.end()));
}

void Game::handleInput() {
    if (!player1_->isDead())
        playerLeftSideInputControls(player1_);
    if (!player2_->isDead())
        playerRightSideInputControls(player2_);
}

void Game::update() {
    window_->update();
    scoreBoard_->update(tanks_.size());
    for (const auto &item: bullets_)
        item->update();

    for (const auto &tank: tanks_)
        tank->update();

    tankCollision::handleAllCollisions(tanks_, stones_, bullets_, wallBuilder_, scoreBoard_);

}

void Game::render() {
    window_->beginDraw();
    draw_all(bullets_, window_);
    draw_all(wallBuilder_.getWalls(), window_);
    draw_all(stones_, window_);
    draw_all(tanks_, window_);
    window_->draw(*scoreBoard_.get());
    scoreBoard_->displayWinner(isGameOver());
    window_->endDraw();
}

bool Game::isDone() const {
    return window_->isDone();
}

void Game::playerLeftSideInputControls(tank_t &player) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player->moveUpward();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player->moveDownward();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->moveBackward();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->moveForward();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        player->rotateTank();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        player->shoot(player, &bullets_);
}

void Game::playerRightSideInputControls(tank_t &player) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player->moveUpward();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player->moveDownward();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player->moveBackward();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player->moveForward();
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        player->rotateTank();
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        player->shoot(player, &bullets_);
}

void Game::setupPlayers() {
    player1_ = std::make_shared<Tank>(BlockSize);
    player1_->setInnerColor(sf::Color::Green);
    player1_->setPosition(grid_.getPositionAt(10));

    player2_ = std::make_shared<Tank>(BlockSize);
    player2_->setInnerColor(sf::Color::Blue);
    player2_->setPosition(grid_.getPositionAt(grid_.getSize() - 5));

    tanks_.push_back(player1_);
    tanks_.push_back(player2_);
    scoreBoard_->AddPlayers(player1_, player2_);
}

bool Game::isGameOver() {
    if (tanks_.size() <= 1)
        return true;
    if (tanks_.size() > 2)
        return player1_->isDead() && player2_->isDead();

    return !player1_->isDead() || !player2_->isDead();
}
