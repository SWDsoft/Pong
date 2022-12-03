#pragma once

#include "Entity.h"
#include "Delta.h"
#include "Random.h"
#include "defs.h"
#include "AABB.h"
#include <iostream>

#include <iostream>
#include <array>

class Ball : public Entity
{
private:
	
	char dir_x,dir_y;

	int wallPopCount;
	int paddlePopCount;

	int lifeTime;

	void ballInit();

	void checkSides(std::array<Entity*, 2> players);

	bool AddBall();

	int speed_x, speed_y;


public:

	void Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls) override;

	int getLifeTime();

	Ball(sf::Vector2f dim, sf::Vector2f pos) : Entity(dim, pos) { ballInit(); }
	~Ball() { DEBUG("called"); };
};

