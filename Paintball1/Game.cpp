#include "Game.h"
#include <iostream>

Game::Game()
{
    for (int p = 0; p < noOfTeams * playersPerTeam; p++)
    {
        Player player;
        player.setPlayerID(p);
        player.setTeamID(p / playersPerTeam);
        players.push_back(player);
    }
    int pCount = 0;
    for (int t = 0; t < noOfTeams; t++)
    {
        std::vector<Player*> tempTeam;
        for (unsigned int i = 0; i < players.size() / noOfTeams; i++)
        {
            tempTeam.push_back(&players.at(pCount));
            pCount++;
        }
        teams.push_back(tempTeam);
    }
}

Game::Game(int noTeams, int pPerTeam)
{
    noOfTeams = noTeams;
    playersPerTeam = pPerTeam;
    for (int p = 0; p < noOfTeams * playersPerTeam; p++)
    {
        Player player;
        player.setPlayerID(p);
        player.setTeamID(p / playersPerTeam);
        players.push_back(player);
    }
    int pCount = 0;
    for (int t = 0; t < noOfTeams; t++)
    {
        std::vector<Player*> tempTeam;
        for (unsigned int i = 0; i < players.size() / noOfTeams; i++)
        {
            tempTeam.push_back(&players.at(pCount));
            pCount++;
        }
        teams.push_back(tempTeam);
    }
}


//getTeams()
std::vector<std::vector<Player*>>& Game::getTeams()
{
    return teams;
}

//getTeam()
std::vector<Player*>& Game::getTeam(int index)
{
    return teams.at(index);
}

//getTeamPlayer()
//dereferencing then passing that address
Player& Game::getTeamPlayer(int teamIndex, int playerIndex)
{
    return *teams.at(teamIndex).at(playerIndex);
}

//getPlayers()
std::vector<Player>& Game::getPlayers()
{
    return players;
}



//Position Teams
//this still needs to be fixed to put the teams evenly across the middle
void Game::positionTeams(sf::Vector2u wSize)
{
    {   float playerWidth = players.at(0).getRadius() * 2.0f,
              teamWidth = (playersPerTeam * playerWidth),
              spacing, offset;
        for (unsigned int t = 0; t < teams.size(); t++)
        {
            spacing = 20.0f;
            offset = 0.0f;
            if (t % 2 == 0)
            {
                for (int p = 0; p < playersPerTeam; p++)
                {
                    teams.at(t).at(p)->setPosition(((wSize.x / 2.0f) - (teamWidth / 2.0f)) + offset, 700.0f);
                    offset += playerWidth + (spacing / playersPerTeam);
                }
            }
            else
            {
                for (int p = 0; p < playersPerTeam; p++)
                {
                    teams.at(t).at(p)->setPosition(((wSize.x / 2.0f) - (teamWidth / 2.0f)) + offset, 20.0f);
                    offset += playerWidth + (spacing / playersPerTeam);
                }
            }
        }
    }
}
