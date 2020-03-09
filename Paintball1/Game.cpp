#include "Game.h"
#include <iostream>

Game::Game()
{
    for (int t = 0; t < noOfTeams; t++)
    {
        Team team;
        for (int p = 0; p < playersPerTeam; p++)
        {

        }
        teams.push_back(team);
    }
}

Game::Game(int noTeams, int pPerTeam)
{
    noOfTeams = noTeams;
    playersPerTeam = pPerTeam;
    for (int i = 0; i < noOfTeams; i++)
    {
        Team team(pPerTeam);
        teams.push_back(team);
    }
}

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

std::vector<Team> Game::getTeams()
{
    return teams;
}

Team Game::getTeamsAt(int index)
{
    return teams.at(index);
}
