#include "Gun.h"


Gun::Gun()
{

}

void Gun::shoot()
{
	if (hopperCount > 0)
	{
		
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