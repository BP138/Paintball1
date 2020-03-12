#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#include "Gun.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    const float plRADIUS = 12.0f;

    int playerID = -1,
        teamID = -1;
    unsigned int ballsInHopper = 200;
    sf::CircleShape player;
    sf::Color plColor;

    sf::Vector2f targetPosition;  
    std::vector<Ball> ballsFired;
    Gun gun;

public:
    Player();
    ~Player(){};

    sf::CircleShape getPlayer();
    float getRadius();

    int getPlayerID();
    void setPlayerID(int pID);

    int getTeamID();
    void setTeamID(int tID);
    
    sf::Vector2f getPosition();
    void setPosition(float x, float y);

    void movePlayer(char key, float dt);

    std::vector<Ball>& getBallsFired();
    void removeBall(int index);
    
    sf::Vector2f calculateTargetVector(sf::Vector2f mousePos);

    void shootGun(sf::Vector2f mousePosition);
};
#endif
