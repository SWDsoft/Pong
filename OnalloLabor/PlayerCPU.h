#pragma once

#include "Entity.h"

#include "Delta.h"

#include "defs.h"
#include <iostream>
#include <array>

class PlayerCPU : public Entity
{
private:
	float acceleration = 1500;
	float breakAcceleration = 50;
	float speed = 0;
	float maxSpeed = 500;
	int currentDirection = 0;
public:

	void Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls) override;
	bool InRangeTop() inline const;
	bool InRangeBottom() inline const;
	PlayerCPU(sf::Vector2f dim, sf::Vector2f pos) : Entity(dim, pos) {}

};

