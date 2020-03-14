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

	bool checkBallCollision(const sf::CircleShape& ball);
	void getCopyOfBunkers(const std::vector<Bunker>& bunkerss);
	//void getCopyOfPlayers(const std::vector<Player>& playerss);

};