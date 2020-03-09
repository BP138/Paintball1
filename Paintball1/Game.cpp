#include "Game.h"
#include "Player.h"
#include "Team.h"

Game::Game()
{
    for (int i = 0; i < teamSize; i++)
    {
        Team team;
        teams.push_back(player);
    }


    for (int i = 0; i < noOfPlayers; i++)
    {
        Player player;
        players.push_back(player);
    }


    int pcount = 0;
    for (int t = 0; t < noOfTeams; t++)
    {
        std::vector<Player*> temp;
        for (unsigned int i = 0; i < players.size() / noOfTeams; i++)
        {
            temp.push_back(&players.at(pcount));
            pcount++;
        }
        teams.push_back(temp);
    }
}