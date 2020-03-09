#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#ifndef TEAM_H
#define TEAM_H



class Team
{
private:
	int teamSize = 5;
	std::vector<Player> team;

public:
	Team();
	Team(int pPerTeam);
	~Team() {};

	int getTeamSize();
	std::vector<Player> getTeam();
	Player getPlayerAt(int index);

};

#endif // !TEAM_H

