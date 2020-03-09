#include "Ball.h"

Ball::Ball()
{
    radius = 5.0f;
    ball.setRadius(radius);
}

Ball::Ball(sf::Vector2f targVector)
{
    radius = 5.0f;
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

void Ball::shootBall(float dt)
{
    //normalize velocity
    float vectorMagnitude = static_cast<float>(sqrt((pow(targetVector.x, 2))+(pow(targetVector.y, 2))));
    sf::Vector2f normalizedVect = targetVector / vectorMagnitude;
    //shoot ball
    ball.move(normalizedVect * speed * dt);
}