#include <vector>
#include "Player.h"
#ifndef GAME_H
#define GAME_H


class Game
{
private:
	int noOfTeams = 2,
		playersPerTeam = 5;
		
	std::vector<Player> players;
	std::vector<std::vector<Player*>> teams;

public:
	Game();
	Game(int noTeams, int pPerTeam);
	~Game() {};

	std::vector<std::vector<Player*>>& getTeams();
	std::vector<Player*>& getTeam(int index);
	Player& getTeamPlayer(int teamIndex, int playerIndex);
	std::vector<Player>& getPlayers();
	void positionTeams(sf::Vector2u wSize);
};
#endif











