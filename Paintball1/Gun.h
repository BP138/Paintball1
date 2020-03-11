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
	
	void shootBall(Ball& ball);
	void fillHopper();
	int getAmmo();
};






#endif // !GUN_H



