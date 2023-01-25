// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "Die.hpp"
#include "Player.hpp"
#include "GameEngine.hpp"

int main() {
    int maxScore = 80;

    std::vector<Die> gameDice;

    gameDice.push_back(Die(12));
    gameDice.push_back(Die(8));

    GameEngine game(maxScore);

    game.addPlayer("Fred");
    game.addPlayer("Bill");
    game.addPlayer("John");

    game.setPlayOrder(gameDice);

    std::cout << game.getPlayerNames();

    std::pair<Player, bool> winStatus(Player("No Win Yet"), false);

    do {
        std::cout << game.playRound(gameDice);
        winStatus = game.gameWinner();
    } while (winStatus.second == false);

    std::cout << winStatus.first.getPlayerName() << " Won! with " << winStatus.first.getCurrentScore() << std::endl;

    return 0;
}

    /*
#include <iostream>
#include <vector>
#include <algorithm>

#include "Die.hpp"
#include "Player.hpp"

int main() {
    int maxScore = 80;

    std::vector<Die> gameDice;

    gameDice.push_back(Die(12));
    gameDice.push_back(Die());

    std::vector<Player> players;
    players.push_back(Player("Stephen"));
    players.push_back(Player("John"));

    do {
    players[0].resetCurrentScore();
    players[1].resetCurrentScore();
    players[0].takeTurn(gameDice);
    players[1].takeTurn(gameDice);
    } while(players[0].getCurrentScore() == players[1].getCurrentScore());

    if(players[0].getCurrentScore() < players[1].getCurrentScore() )
        std::reverse(players.begin(),players.end());

    players[0].resetCurrentScore();
    players[1].resetCurrentScore();

    do {
        for (std::size_t i = 0; i < 2; i++) {
            players[i].takeTurn(gameDice);
            std::cout << players[i].getCurrentScore() << "\t";
        }
        std::cout << std::endl;

    } while (players[0].getCurrentScore() < maxScore && players[1].getCurrentScore() < maxScore);

    int winner = 1;
    if (players[1].getCurrentScore() < maxScore)
        winner = 0;

    std::cout << players[winner].getPlayerName() << " Won!";
   
} 
*/