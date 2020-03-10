#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#include "Gun.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    const float plRADIUS = 8.0f;
    int playerID = -1,
        teamID = -1;
    sf::Vector2f targetPosition;    
        
    sf::Color plColor;
    sf::CircleShape player;
    std::vector<Ball> balls;
    Gun gun;

public:
    Player();
    ~Player(){};

    sf::CircleShape getPlayer();

    void setPlayerID(int pID);
    int getPlayerID();
    void setTeamID(int tID);
    int getTeamID();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void movePlayer(char key, float dt);
    float getRadius();
    sf::Vector2f calculateTargetVector(sf::Vector2f mousePos);

    void shoot(sf::Vector2f mousePosition);
    void getBalls(std::vector<Ball> ballsOnField&);
};
#endif
