#include "Render.h"

Render::Render(World& world,sf::RenderWindow& rwindow) : world(world), rwindow(rwindow)
{

	defaultFont.loadFromFile("consola.ttf");

	scorePlayer.setFont(defaultFont);
	scorePlayer.setString("0");
	scorePlayer.setCharacterSize(80);
	scorePlayer.setPosition(sf::Vector2f{ (CONFIG::screen::w / 2 - 100),50 });

	scoreCpu.setFont(defaultFont);
	scoreCpu.setString("0");
	scoreCpu.setCharacterSize(80);
	scoreCpu.setPosition(sf::Vector2f{ (CONFIG::screen::w / 2 + 70),50 });

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

	scorePlayer.setString(std::to_string(world.getPlayers()[0]->score));
	scoreCpu.setString(std::to_string(world.getPlayers()[1]->score));

	rwindow.draw(scorePlayer);
	rwindow.draw(scoreCpu);

	rwindow.draw(centerLine,2,sf::Lines);

}

