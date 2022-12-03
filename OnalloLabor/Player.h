#pragma once

#include "Delta.h"


#include "Entity.h"
#include "Ball.h"

#include <iostream>
#include <array>

class Player : public Entity
{
public:

	void Control(std::array<Entity*, 2> players, std::vector<Entity*>& balls) override;

	Player(sf::Vector2f dim, sf::Vector2f pos) : Entity(dim, pos) {}

};

