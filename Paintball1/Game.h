#include <vector>
#include "Player.h"
#ifndef GAME_H
#define GAME_H


class Game
{
private:
	int noOfTeams = 2,
		playersPerTeam = 5;
		
	std::vector<Player*> players;
	std::vector<std::vector<Player>> teams;

public:
	Game();
	Game(int noTeams, int pPerTeam);
	~Game() {};

	std::vector<std::vector<Player>> getTeams();
	std::vector<Player> getTeam(int index);
	std::vector<Player*> getPlayers();
	Player getTeamPlayer(int teamIndex, int playerIndex);
	//void positionTeams(sf::Vector2u wSize);
};
#endif