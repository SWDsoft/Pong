#include "World.h"

std::array<Entity*, 2> &World::getPlayers()
{
	return players;
}

std::vector<Entity*> World::getBalls()
{
	return balls;
}

void
World::UpdateEntities()
{
	for (auto i : players)
	{
		i->Control(players,balls);
	}
	
	for (auto i = 0; i < balls.size(); i++)
	{
		auto ball = dynamic_cast<Ball*>(balls.at(i));

		ball->Control(players, balls);

		/*if (ball->getLifeTime() > CONFIG::ball::max_lifetime)
		{
			delete ball;
			balls.erase(balls.begin()+i);
			--i;
		}*/
		
	}

}

