#include "Gun.h"


Gun::Gun()
{

}

void Gun::shootBall(Ball &ball)
{
	if (hopperCount > 0)
	{

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
