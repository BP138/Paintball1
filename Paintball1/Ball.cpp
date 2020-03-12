#include "Ball.h"
#include <iostream>
Ball::Ball()
{
    ball.setRadius(radius);
}

Ball::Ball(sf::Vector2f targVector, sf::Vector2f spawnPosition)
{
    ball.setRadius(radius);
    ball.setPosition(spawnPosition);
    targetVector = targVector;
    ball.setFillColor(sf::Color::Blue);
    ball.setOrigin(radius, radius);
}

sf::CircleShape Ball::getBall()
{
    return ball;
}

float Ball::getVelocity()
{
    return velocity;
}

float Ball::getLifeTime()
{
    return lifeTime;
}

void Ball::setPosition(sf::Vector2f pPosition)
{
    ball.setPosition(pPosition);
}

void Ball::updateBall(float dt)
{
    ball.move(targetVector * velocity * dt);
    std::cout << "Target vector: " << targetVector.x << " " << targetVector.y << std::endl;
    lifeTime = lifeTime + dt;
}