#include "Bunker.h"

Bunker::Bunker()
{}

Bunker::Bunker(int bunker)
{
	switch (bunker)
	{
	case 0: //Cylinder
		cylinder.setFillColor(sf::Color::Cyan);
		cylinder.setRadius(42);
		cylinder.setPosition(360, 450);
		cylinder.setOrigin(42,42);
	}
}


sf::CircleShape Bunker::getBunker()
{
	return cylinder;
}