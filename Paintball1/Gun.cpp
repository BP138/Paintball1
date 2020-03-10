#include "Gun.h"


Gun::Gun()
{

}

Ball Gun::shoot(sf::Vector2f targetVect, float dt)
{
	if (hopperCount > 0)
	{
		Ball paintball(targetVect);
		paintball.shootBall(dt);
		hopperCount--;
		return paintball;
	}
}

void Gun::fillHopper()
{
	hopperCount = hopperCapacity;
}

int Gun::getAmmo()
{
	return hopperCount;
}
