#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bunker.h"

#include "Player.h"

class Collision
{
private:

	std::vector<Bunker> bunkers;
	std::vector<Player>* players;

public:
	Collision();
	~Collision() {};

	void getCopyOfBunkers(const std::vector<Bunker>& bunkerss);
	void getCopyOfPlayers(std::vector<Player>& playerss);
	bool checkBallCollision(Ball& ball);

	

};