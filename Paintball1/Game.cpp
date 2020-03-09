#include "Game.h"
#include <iostream>

Game::Game()
{
    for (int t = 0; t < noOfTeams; t++)
    {
        std::vector<Player> tempTeam;
        for (int p = 0; p < playersPerTeam; p++)
        {
            Player player;
            player.setPlayerID(p);
            tempTeam.push_back(player);
        }
        teams.push_back(tempTeam);
        for (int i = 0; i < playersPerTeam; i++)
        {
            players.push_back(&teams.at(t).at(i));
        }
    }
}

Game::Game(int noTeams, int pPerTeam)
{
    noOfTeams = noTeams;
    playersPerTeam = pPerTeam;
    for (int t = 0; t < noOfTeams; t++)
    {
        std::vector<Player> tempTeam;
        for (int p = 0; p < playersPerTeam; p++)
        {
            Player player;
            player.setPlayerID(p);
            tempTeam.push_back(player);
        }
        teams.push_back(tempTeam);
        for (int i = 0; i < playersPerTeam; i++)
        {
            players.push_back(&teams.at(t).at(i));
        }
    }
}


//Gets teams vector (vector of vector)
std::vector<std::vector<Player>> Game::getTeams()
{
    return teams;
}

//Returns vector of players from teams vector
std::vector<Player> Game::getTeam(int index)
{
    return teams.at(index);
}

std::vector<Player*> Game::getPlayers()
{
    return players;
}

//Return a player shape specified
Player Game::getTeamPlayer(int teamIndex, int playerIndex)
{
    return teams.at(teamIndex).at(playerIndex);
}


/*
//Position Teams
void Game::positionTeams(sf::Vector2u wSize)
{
    {
        float teamWidth = (teams.at(0).getTeamSize() * 
                            (teams.at(0).getTeam().at(0).getRadius() * 2));
        float spacing; 
        float offset;
        for (int t = 0; t < teams.size(); t++)
        {
            spacing = (teams.at(t).getTeam().at(0).getRadius() * 2.0f) + 5.0f;
            offset = 0.0f;

            if (t % 2 == 0)
            {
                for (int p = 0; p < teams.at(t).getTeamSize(); p++)
                {
                    teams.at(t).getTeam().at(p).setPlayerPosition(
                        ((wSize.x / 2) - teamWidth / 2.0f) + offset, 700.0f);
                    std::cout << " " << teams.at(t).getTeam().at(p).getRadius();
                    offset += spacing;
                }
            }
            else
            {
                for (int p = 0; p < teams.at(t).getTeamSize(); p++)
                {
                    teams.at(t).getTeam().at(p).setPlayerPosition(
                        ((wSize.x / 2) - teamWidth / 2.0f) + offset, 20.0f);
                    std::cout << " " << teams.at(t).getTeam().at(p).getRadius();
                    offset += spacing;
                }
            }
        }
    }
}
*/

