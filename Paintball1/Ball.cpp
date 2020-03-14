#include "Ball.h"
#include <iostream>
Ball::Ball(sf::Vector2f spawnPos)
{
    spawnPosition = spawnPos;
    ball.setRadius(radius);
    ball.setPosition(spawnPosition);
    ball.setFillColor(sf::Color::Blue);
    ball.setOrigin(radius, radius);
}

Ball::Ball(sf::Vector2f targPosition, sf::Vector2f spawnPos)
{
    targetPosition = targPosition;
    spawnPosition = spawnPos;
    targetVector = targPosition - spawnPos;
    calculateNormalizedVector();
    ball.setRadius(radius);
    ball.setPosition(spawnPosition);
    ball.setFillColor(sf::Color::Blue);
    ball.setOrigin(radius, radius);
}

sf::CircleShape Ball::getBall() { return ball; }

float Ball::getVelocity() { return velocity; }

float Ball::getLifeTime() { return lifeTime; }

void Ball::setPosition(sf::Vector2f pPosition)
{
    ball.setPosition(pPosition);
}

void Ball::updateBall(float dt)
{
    ball.move(normalizedVect * velocity * dt);
    lifeTime = lifeTime + dt;
}


void Ball::calculateNormalizedVector()
{
    normalizedVect = targetVector / static_cast<float>(sqrt((pow(targetVector.x, 2)) +
        (pow(targetVector.y, 2))));
    std::cout << "Distance: " << sqrt(pow(targetPosition.x - spawnPosition.x, 2) + pow(targetPosition.y - spawnPosition.y, 2)) << std::endl;
    std::cout << "target vector: " << targetVector.x << " " << targetVector.y << std::endl;
    std::cout << "Normalized vector: " << normalizedVect.x << " " << normalizedVect.y << std::endl << std::endl;
}

