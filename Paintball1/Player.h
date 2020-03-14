#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"




class Player
{
private:
    float plRADIUS = 12.0f;

    int playerID = -1,
        teamID = -1;

    bool hit = false;

    unsigned int ballsInHopper = 200;
    sf::CircleShape player;
    sf::Color plColor;

    sf::Vector2f targetPosition;
    std::vector<Ball> ballsFired;

public:
    Player();
    ~Player() {};

    sf::CircleShape getPlayer();
    float getRadius();
    int getPlayerID();
    void setPlayerID(int pID);
    int getTeamID();
    void setTeamID(int tID);
    bool getHitStatus();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void movePlayer(char key, float dt);
    std::vector<Ball>& getBallsFired();
    void removeBall(int index);
    void shootGun(sf::Vector2f mousePosition);
    void setHit(bool h);
};

