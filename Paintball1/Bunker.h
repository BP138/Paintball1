#pragma once
#include <SFML/Graphics.hpp>





class Bunker
{
private:
	int sides;
	int radius = 0;

	sf::Vector2f size;
	sf::CircleShape cylinder;
	sf::RectangleShape rectangle;
public:
	int bunkerType = 1000;
	Bunker();
	Bunker(int bunker);
	~Bunker() {};
	sf::CircleShape getCircleBunker();
	sf::RectangleShape getRecBunker();
};

