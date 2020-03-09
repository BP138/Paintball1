#include "Team.h"

Team::Team()
{

    for (int i = 0; i < teamSize; i++)
    {
        Player player;
        team.push_back(player);
    }
}

Team::Team(Player* &mPlayer)
{
    team.resize(teamSize);

    for (int i = 0; i < teamSize; i++)
    {
        Player player;
        team.push_back(player);
    }
}