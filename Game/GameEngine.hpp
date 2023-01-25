#include <vector>
#include <optional>

#include "Player.hpp"

class GameEngine {
private:
protected:
	int winningScore;
	std::vector<Player> players;

public:
	GameEngine(int winningScore);

	void addPlayer(std::string playerName);
	std::string playRound(std::vector<Die>& gameDice);
	void clearPlayerScores();
	std::string getPlayerNames();
	void setPlayOrder(std::vector<Die>& gameDice);
	std::pair<Player, bool> gameWinner();
};

GameEngine::GameEngine(int winningScore) {
	this->winningScore = winningScore;
}

void GameEngine::addPlayer(std::string playerName) {
	this->players.push_back(Player(playerName));
}

std::string GameEngine::playRound(std::vector<Die>& gameDice) {
	std::string roundDetails = "";

	for (auto& currentPlayer : this->players) {
		currentPlayer.takeTurn(gameDice);
		roundDetails.append(std::to_string(currentPlayer.getCurrentScore()) + "\t");
	}
	return roundDetails += "\n";
}

void GameEngine::clearPlayerScores() {
	for (auto& currentPlayer : this->players) {
		currentPlayer.resetCurrentScore();
	}
}

std::string GameEngine::getPlayerNames() {
	std::string playerDetails = "";

	for (auto& currentPlayer : this->players) {
		playerDetails.append(currentPlayer.getPlayerName() + "\t");
	}
	return playerDetails += "\n";
}

void GameEngine::setPlayOrder(std::vector<Die>& gameDice) {

	for (auto& currentPlayer : this->players) {
		currentPlayer.takeTurn(gameDice);
	}

	std::stable_sort(this->players.begin(), this->players.end());
	std::reverse(this->players.begin(), this->players.end());

}

std::pair<Player, bool> GameEngine::gameWinner() {
	for (auto& currentPlayer : this->players) {
		if (currentPlayer.getCurrentScore() >= this->winningScore) {
			return std::pair<Player, bool>(currentPlayer, true);
		}
	}
	return std::pair<Player, bool>(Player("NoWinYet"), false);
}