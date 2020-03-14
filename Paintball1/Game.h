#pragma once
#include <vector>
#include "Bunker.h"
#include "Player.h"
#include "Collision.h"


class Game
{
private:
	int noOfTeams = 2,
		playersPerTeam = 5;
	std::vector<Bunker> bunkers;
	std::vector<Player> players;
	std::vector<std::vector<Player*>> teams;
	Collision collision;

public:
	Game();
	Game(int noTeams, int pPerTeam);
	~Game() {};


	std::vector<Bunker>& getBunkers();
	std::vector<std::vector<Player*>>& getTeams();
	std::vector<Player*>& getTeam(int index);
	Player& getTeamPlayer(int teamIndex, int playerIndex);
	std::vector<Player>& getPlayers();
	int getNumberofPlayers();
	Collision& getCollision();
	void positionTeams(sf::Vector2u wSize);


};


