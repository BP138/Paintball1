#include "Player.h"
#include <iostream>


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

bool Player::getHitStatus()
{
    return hit;
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
    switch (key)
    {
    case 'w': player.move(0.0f, -200.0f * dt); break;
    case 'a': player.move(-200.0f * dt, 0.0f); break;
    case 'd': player.move(200.0f * dt, 0.0f); break;
    case 's': player.move(0.0f, 200.0f * dt); break;
    default: break;
    }
}

//get balls fired
std::vector<Ball>& Player::getBallsFired()
{
    return ballsFired;
}

//remove ball at
void Player::removeBall(int index)
{
    ballsFired.erase(ballsFired.begin() + index);
}

//shoot
void Player::shootGun(sf::Vector2f targetPosition)
{
    if (ballsInHopper > 0)
    {
        Ball paintball(targetPosition, player.getPosition());
        paintball.setShooterID(teamID, playerID);
        ballsFired.push_back(paintball);
        ballsInHopper--;
    }
    else std::cout << "Hopper empty";
}

void Player::setHit(bool h)
{
    hit = h;
}