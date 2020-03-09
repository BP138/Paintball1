#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


class Player
{
private:
    const float plRADIUS = 8.0f;
    sf::Color plColor;
    sf::CircleShape player;

public:
    Player();
    ~Player(){};
    sf::CircleShape getPlayer();
    sf::Vector2f getPosition();
    void setPlayerPosition(float x, float y);
    void movePlayer(char key, float dt);
    float getRadius();

};
#endif
