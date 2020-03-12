#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"


Player::Player()
{
    plColor = sf::Color::Red;
    player.setRadius(plRADIUS);
    player.setFillColor(plColor);
    player.setOrigin(plRADIUS, plRADIUS);
};


//Get Player CircleShape
sf::CircleShape Player::getPlayer()
{
    return player;
}

//Get player's radius
float Player::getRadius()
{
    return plRADIUS;
}


//Player ID getter and setter
int Player::getPlayerID()
{
    return playerID;
}
void Player::setPlayerID(int pID)
{
    playerID = pID;
}


//Player's team ID getter and setter
int Player::getTeamID()
{
    return teamID;
}
void Player::setTeamID(int tID)
{
    teamID = tID;
}


//Player position getter and setter
sf::Vector2f Player::getPosition()
{
    return player.getPosition();
}
void Player::setPosition(float x, float y)
{
    player.setPosition(x, y);
}


//movePlayer
void Player::movePlayer(char key, float dt)
{
    switch(key)
    {
        case 'w': player.move(0.0f, -200.0f * dt); break;
        case 'a': player.move(-200.0f * dt, 0.0f); break;
        case 'd': player.move(200.0f * dt, 0.0f); break;
        case 's': player.move(0.0f, 200.0f * dt); break;
        default: break;
    }
}


//Calculate target direction
sf::Vector2f Player::calculateTargetVector(sf::Vector2f mousePos)
{
    sf::Vector2f targetVector = mousePos - player.getPosition();
    sf::Vector2f normalizedVect = targetVector / static_cast<float>(sqrt((pow(targetVector.x, 2)) +
        (pow(targetVector.y, 2))));
    return normalizedVect;
}


//shoot
void Player::shootGun(sf::Vector2f targetPosition)
{
    if (ballsInHopper > 0)
    {
        //std::cout << "Target position: " << "(" << targetPosition.x << "," << targetPosition.y << ")" << std::endl;
        //std::cout << "Normalized vector: " << "(" << calculateTargetVector(targetPosition).x << "," << calculateTargetVector(targetPosition).y << ")" << std::endl;
        Ball paintball(calculateTargetVector(targetPosition), player.getPosition());
        ballsFired.push_back(paintball);
        ballsInHopper--;
    }
    else std::cout << "Hopper empty";
    
}


std::vector<Ball>& Player::getBallsFired()
{
    return ballsFired;
}
void Player::removeBall(int index)
{
    ballsFired.erase(ballsFired.begin() + index);
}