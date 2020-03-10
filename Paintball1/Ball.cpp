#include "Ball.h"
#include <iostream>
Ball::Ball()
{
    ball.setRadius(radius);
}

Ball::Ball(sf::Vector2f targVector)
{
    ball.setRadius(radius);
    targetVector = targVector;
    ball.setFillColor(sf::Color::Blue);
    ball.setOrigin(radius, radius);
}

sf::CircleShape Ball::getBall()
{
    return ball;
}

void Ball::setPosition(sf::Vector2f pPosition)
{
    ball.setPosition(pPosition);
}

void Ball::shootBall(float dt, float velocity)
{
    ball.move(targetVector * velocity * dt);
}
