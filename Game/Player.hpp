#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Die.hpp"

class Player {
private:
    int currentScore;
    std::string playerName;

public:
    Player();
    Player(std::string playerName);
    std::string getPlayerName();
    void takeTurn(std::vector<Die> &Dice);
    int getCurrentScore();
    void resetCurrentScore();

    bool operator<(const Player& rhPlayer) const { return this->currentScore < rhPlayer.currentScore; }
    

};

Player::Player() {
    this->currentScore = 0;
    this->playerName = "Unknown Player";
}

Player::Player(std::string playerName) {
    this->currentScore = 0;
    this->playerName = playerName;
}

void Player::takeTurn(std::vector<Die> &Dice) {

    for (auto& currentDie : Dice) {
        currentDie.roll();
        this->currentScore += currentDie.getLastRoll();
    }
}

std::string Player::getPlayerName() {
    return this->playerName;
}

int Player::getCurrentScore() {
    return this->currentScore;
}

void Player::resetCurrentScore() {
    this->currentScore = 0;
}
