#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"


Player::Player()
{
    plColor = sf::Color::Red;
    player.setRadius(plRADIUS);
    player.setFillColor(plColor);
    player.setOrigin(plRADIUS, plRADIUS);
    ammo = 200;
};


sf::CircleShape Player::getPlayer()
{
    return player;
}


void Player::setPlayerID(int pID)
{
    playerID = pID;
}

int Player::getPlayerID()
{
    return playerID;
}

void Player::setTeamID(int tID)
{
    teamID = tID;
}

int Player::getTeamID()
{
    return teamID;
}


sf::Vector2f Player::getPosition()
{
    return player.getPosition();
}

void Player::setPosition(float x, float y)
{
    player.setPosition(x, y);
}


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

float Player::getRadius()
{
    return plRADIUS;
}


void Player::shoot(sf::Vector2f targetPosition)
{
    if (gun.getAmmo() > 0)
    {
        Ball paintball(targetPosition);
        balls.push_back(paintball);
        gun.removeAmmo();
    }
}

void Player::getBalls(std::vector<Ball> ballsOnField&)
{
    for (auto &ball : balls)
    {
        ballsOnField.push_back(ball);
    }
}

void Player::calculateTargetPosition()
{
    targetPosition = ()
}