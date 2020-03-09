#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>


class Ball
{
private:
    float radius;
    sf::CircleShape ball;
    sf::Vector2f targetVector;
    float speed = 700.0f;

public:
    Ball();
    Ball(sf::Vector2f targVector);
    ~Ball(){};
    sf::CircleShape getBall();
    void setPosition(sf::Vector2f pPosition);
    void shootBall(float dt);

};
#endif
