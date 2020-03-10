#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


class Player
{
private:
    const float plRADIUS = 8.0f;
    int playerID = -1,
        teamID = -1;
    sf::Color plColor;
    sf::CircleShape player;

public:
    Player();
    ~Player(){};
    sf::CircleShape getPlayer();
    void setPlayerID(int pID);
    int getPlayerID();
    void setTeamID(int tID);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void movePlayer(char key, float dt);
    float getRadius();

};
#endif
