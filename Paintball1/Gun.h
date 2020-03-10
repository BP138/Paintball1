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
	
	Ball shoot(sf::Vector2f targetVect, float dt);
	void fillHopper();
	int getAmmo();
};






#endif // !GUN_H



