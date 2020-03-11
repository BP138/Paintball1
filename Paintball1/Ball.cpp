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

void Ball::setPosition(sf::Vector2f pPosition)
{
    ball.setPosition(pPosition);
}

void Ball::shootBall(float dt)
{
    ball.move(targetVector * velocity * dt); 
}
