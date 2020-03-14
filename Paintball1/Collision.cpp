#include "Collision.h"
#include <iostream>

Collision::Collision()
{}


void Collision::getCopyOfBunkers(const std::vector<Bunker>& bunkerss)
{
    for (auto& bunk : bunkerss)
    {
        bunkers.push_back(bunk);
    }
}
/*
void Collision::getCopyOfPlayers(const std::vector<Player>& playerss)
{
    for (auto& playr : playerss)
    {
        players->push_back(playr);
    }
}
*/

bool Collision::checkBallCollision(const sf::CircleShape& ball)
{
    for (auto& b : bunkers)
    {
        if (b.bunkerType == 0) //circle bunker
        {
            if (sqrt(pow(ball.getPosition().x - b.getCircleBunker().getPosition().x, 2) + pow(ball.getPosition().y - b.getCircleBunker().getPosition().y, 2))
                < ball.getRadius() + b.getCircleBunker().getRadius())
            {
                std::cout << "Collided" << std::endl;
                return true;
            }
        }
        else if (b.bunkerType == 1) //rect bunker
        {
            for (int X = b.getRecBunker().getPosition().x; X < b.getRecBunker().getPosition().x + b.getRecBunker().getSize().x; X++)
            {
                for (int Y = b.getRecBunker().getPosition().y; Y < b.getRecBunker().getPosition().y + b.getRecBunker().getSize().y * 0.02; Y++)
                {
                    if (sqrt(pow(ball.getPosition().x - X, 2) + pow(ball.getPosition().y - Y, 2))
                        < ball.getRadius())
                    {
                        std::cout << "Hit!" << std::endl;
                        return true;
                    }

                }
            }
        }

    }
    for (auto& p : *players)
    {
        if (ball.get)
        {
            if (sqrt(pow(ball.getPosition().x - b.getCircleBunker().getPosition().x, 2) + pow(ball.getPosition().y - b.getCircleBunker().getPosition().y, 2))
                < ball.getRadius() + b.getCircleBunker().getRadius())
            {
        }
    }
    return false;
}




/*

sf::Vector2f size(100.0f, 100.0f);
sf::RectangleShape rect(size);
rect.setPosition(420, 700);


if (game.getPlayers().at(0).getBallsFired().size() > 0)
{
    for (int X = rect.getPosition().x; X < rect.getPosition().x + size.x; X++)
    {
        for (int Y = rect.getPosition().y; Y < rect.getPosition().y + size.y * 0.01f; Y++)
        {
            if (sqrt(pow(X - game.getPlayers().at(0).getBallsFired().at(0).getBall().getPosition().x, 2) + pow(Y - game.getPlayers().at(0).getBallsFired().at(0).getBall().getPosition().y, 2))
                < game.getPlayers().at(0).getBallsFired().at(0).getBall().getRadius())
            {
                std::cout << "Hit!" << std::endl;
            }

        }
    }
}
*/

/*
void Collision::checkBallCollision()
{
    for (int p = 0; p < players->size(); p++)
    {
        if (players->at(p).getBallsFired().size() > 0)
        {
            for (auto& bunk : bunkers)
            {
                for (int X = bunk.getBunker().getPosition().x; X < bunk.getBunker().getPosition().x + bunk.getBunker().getRadius() * 2; X++)
                {
                    for (int Y = bunk.getBunker().getPosition().y; Y < bunk.getBunker().getPosition().y + (bunk.getBunker().getRadius() * 2 * .02f); Y++)
                    {
                        for (int b = 0; b < players->at(0).getBallsFired().size(); b++)
                        {
                            if (sqrt(pow(X - players->at(0).getBallsFired().at(0).getBall().getPosition().x, 2) + pow(Y - game.getPlayers().at(0).getBallsFired().at(0).getBall().getPosition().y, 2))
                                < game.getPlayers().at(0).getBallsFired().at(0).getBall().getRadius())
                            {
                                std::cout << "Hit!" << std::endl;
                            }
                        }

                    }
                }
            }
        }
    }
}
*/

