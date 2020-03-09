#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player()
{
    plColor = sf::Color::Red;
    player.setRadius(plRADIUS);
    player.setFillColor(plColor);
    player.setOrigin(plRADIUS, plRADIUS);
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
