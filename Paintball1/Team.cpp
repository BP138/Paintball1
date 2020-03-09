#include "Team.h"

Team::Team()
{
    for (int i = 0; i < teamSize; i++)
    {
        Player player;
        team.push_back(player);
    }
}

Team::Team(int pPerTeam)
{
    teamSize = pPerTeam;
    for (int i = 0; i < teamSize; i++)
    {
        Player player;
        team.push_back(player);
    }
}

int Team::getTeamSize()
{
    return team.size();
}

std::vector<Player> Team::getTeam()
{
    return team;
}

Player Team::getPlayerAt(int index)
{
    return team.at(index);
}