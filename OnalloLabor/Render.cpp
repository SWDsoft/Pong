#include "Render.h"

Render::Render(World& world,sf::RenderWindow& rwindow) : world(world), rwindow(rwindow)
{
	
}

void Render::RenderObjects()
{
	for (auto i : world.getPlayers())
	{
		rwindow.draw(i->getBody());
	}
	for (auto i : world.getBalls())
	{
		rwindow.draw(i->getBody());
	}
}

