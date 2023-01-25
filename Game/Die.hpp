#pragma once

#include <random>
#include "RandomIntGenerator.hpp"

class Die {
public:
    Die(int numberOfSides);
    Die();

    void setNumberOfSides(int numberOfSides);
    int getNumberOfSides();

    void roll();
    bool hasBeenRolled();
    int  getLastRoll();



protected:

    RandomIntGenerator randomInt;
    int lastRoll = 0;
    int sides;

};

Die::Die() {
    this->sides = 6;
    this->lastRoll = 0;
    randomInt.setRange(1, this->sides);
}

Die::Die(int numberOfSides) {
    this->sides = numberOfSides;
    this->lastRoll = 0;
    randomInt.setRange(1, this->sides);
}

void Die::setNumberOfSides(int numberOfSides) {
    this->sides = numberOfSides;
    this->lastRoll = 0;
    randomInt.setRange(1, this->sides);
}

int Die::getNumberOfSides() {
    return this->sides;
}

int Die::getLastRoll() {
    return this->lastRoll;
}

bool Die::hasBeenRolled() {
    return this->lastRoll > 0;
}

void Die::roll() {
    this->lastRoll = randomInt.next();
}
