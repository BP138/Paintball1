#include <vector>
#include "Team.h"
#ifndef GAME_H
#define GAME_H


class Game
{
private:
	int playersPerTeam = 5,
		noOfTeams = 2;
	std::vector<Team> teams;

public:
	Game();
	Game(int noTeams, int pPerTeam);
	~Game() {};

	void positionTeams(sf::Vector2u wSize);
	std::vector<Team> getTeams();
	Team getTeamsAt(int index);
};
#endif