#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    const float plRADIUS = 8.0f;
    int playerID = -1,
        teamID = -1;
    sf::Color plColor;
    sf::CircleShape player;
    std::vector<Ball> balls;

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

    void shoot(sf::Vector2f mousePosition);
};
#endif
