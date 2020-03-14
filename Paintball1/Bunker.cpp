#include "Bunker.h"

Bunker::Bunker()
{}

Bunker::Bunker(int bunker)
{
	switch (bunker)
	{
	case 0: //Cylinder
		sides = 2;
		cylinder.setFillColor(sf::Color::Cyan);
		cylinder.setOutlineColor(sf::Color::Black);
		cylinder.setOutlineThickness(1.75f);
		cylinder.setRadius(42);
		cylinder.setPosition(360, 450);
		cylinder.setOrigin(42, 42);
		bunkerType = 0;
		break;

	case 1: //Square
		sides = 4;
		size.x = 100; size.y = 100;
		rectangle.setFillColor(sf::Color::Magenta);
		rectangle.setOutlineColor(sf::Color::Black);
		rectangle.setOutlineThickness(1.75f);
		rectangle.setSize(size);
		rectangle.setPosition(20, 20);
		bunkerType = 1;
	}
}

sf::CircleShape Bunker::getCircleBunker()
{
	return cylinder;
}

sf::RectangleShape Bunker::getRecBunker()
{
	return rectangle;
}