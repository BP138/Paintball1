#pragma once
#include <SFML/Graphics.hpp>


class Ball
{
private:
    sf::CircleShape ball;
    int shooterID = -1,
        teamID = -1;
    float radius = 3.1f,
        speed = 700.0f,
        lifeTime = 0;
    sf::Vector2f targetVector,
        targetPosition,
        spawnPosition,
        normalizedVect;
    float velocity = 500.0f;

public:
    Ball(sf::Vector2f spawnPos);
    Ball(sf::Vector2f targPosition, sf::Vector2f spawnPosition);
    ~Ball() {};

    sf::CircleShape getBall();
    float getVelocity();
    void setShooterID(int tID, int pID);
    int getShooterID();
    int getTeamID();
    float getLifeTime();
    void setPosition(sf::Vector2f pPosition);
    void updateBall(float dt);
    void calculateNormalizedVector();

};
