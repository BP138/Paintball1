#include <SFML/Graphics.hpp>
#ifndef BUNKER_H
#define BUNKER_H



class Bunker
{
private: 
	int sides;
	sf::CircleShape cylinder;
public: 
	Bunker();
	Bunker(int bunker);
	~Bunker() {};
	sf::CircleShape getBunker();
};
#endif // !BUNKER_H
