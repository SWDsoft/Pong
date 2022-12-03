#pragma once

#include "World.h"

class Render
{
private:
	World& world;
	sf::RenderWindow& rwindow;

public:

	Render(World& world, sf::RenderWindow& rwindow);

	void RenderObjects();
};

