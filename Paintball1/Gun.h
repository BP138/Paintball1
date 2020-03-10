#include <vector>
#include "Ball.h"

#ifndef GUN_H
#define GUN_H

class Gun
{
private:
	int hopperCapacity = 200,
		hopperCount = 0;
	std::vector<Ball> hopper;
public:
	Gun();
	~Gun() {};
	
	void shoot(sf::Vector2f targetVect);
	int getAmmo();
	void removeAmmo();
};






#endif // !GUN_H



