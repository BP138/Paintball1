#include "Bunker.h"

Bunker::Bunker(){}

Bunker::Bunker(int bunker)
{
	switch (bunker)
	{
	case 0: //Cylinder
		cylinder.setFillColor(sf::Color::Cyan);
		cylinder.setOutlineColor(sf::Color::Black);
		cylinder.setOutlineThickness(1.75f);
		cylinder.setRadius(42);
		cylinder.setPosition(20, 450);
		cylinder.setOrigin(42, 42);
		bunkerType = 0;
		break;

	case 1: //Square
		size.x = 100; size.y = 100;
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setOutlineColor(sf::Color::Black);
		rectangle.setOutlineThickness(1.75f);
		rectangle.setSize(size);
		rectangle.setPosition(360, 450);
		bunkerType = 1;
		break;
	}
}

//get circle bunker
sf::CircleShape Bunker::getCircleBunker()
{
	return cylinder;
}

//get rectangle bunker
sf::RectangleShape Bunker::getRecBunker()
{
	return rectangle;
}