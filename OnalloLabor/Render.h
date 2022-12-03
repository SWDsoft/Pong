#pragma once

#include "World.h"

class Render
{
private:
	World& world;
	sf::RenderWindow& rwindow;
	sf::Font defaultFont;
	sf::Text scorePlayer,scoreCpu;

	//Center line
	sf::Vertex centerLine[2] =
	{
		sf::Vertex(sf::Vector2f(CONFIG::screen::w/2, 0)),
		sf::Vertex(sf::Vector2f(CONFIG::screen::w / 2, CONFIG::screen::h))
	};

public:

	Render(World& world, sf::RenderWindow& rwindow);

	void RenderObjects();
};

