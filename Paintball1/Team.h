#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#ifndef GAME_H
#define GAME_H

class Team
{
private:
	int teamSize = 5;
	std::vector<Player> team;

public:
	Team();
	Team(Player* &mPlayer);
	~Team() {};



};

#endif // !GAME_H

