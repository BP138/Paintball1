#include "Game.h"
#include <iostream>

Game::Game()
{
    int IDcounter = 0;
    for (int t = 0; t < noOfTeams; t++)
    {
        std::vector<Player*> tempTeam;
        for (int p = 0; p < playersPerTeam; p++)
        {
            Player player;
            player.setPlayerID(IDcounter);
            player.setTeamID(t);
            players.push_back(player);
            tempTeam.push_back(&players.at(IDcounter));
        }
        teams.push_back(tempTeam);
    }
}

Game::Game(int noTeams, int pPerTeam)
{
    noOfTeams = noTeams;
    playersPerTeam = pPerTeam;
    int IDcounter = 0;
    for (int t = 0; t < noOfTeams; t++)
    {
        std::vector<Player*> tempTeam;
        for (int p = 0; p < playersPerTeam; p++)
        {
            Player player;
            player.setPlayerID(IDcounter);
            player.setTeamID(t);
            players.push_back(player);
            tempTeam.push_back(&players.at(IDcounter));
            IDcounter++;
        }
        teams.push_back(tempTeam);
    }
}


//getTeams()
std::vector<std::vector<Player*>> Game::getTeams()
{
    return teams;
}

//getTeam()
std::vector<Player*> Game::getTeam(int index)
{
    return teams.at(index);
}

//getTeamPlayer()
Player Game::getTeamPlayer(int teamIndex, int playerIndex)
{
    return *teams.at(teamIndex).at(playerIndex);
}

//getPlayers()
std::vector<Player> Game::getPlayers()
{
    return players;
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

