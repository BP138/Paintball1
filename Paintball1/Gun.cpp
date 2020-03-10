#include "Gun.h"


Gun::Gun()
{

}

void Gun::shoot(sf::Vector2f targetVect)
{
	if (hopperCount > 0)
	{
		Ball paintball(targetVect);
		paintball.shootBall();
		hopperCount--;
	}
}


int Gun::getAmmo()
{
	return hopperCount;
}

void Gun::removeAmmo()
{
	hopperCount = hopperCount - 1;
}