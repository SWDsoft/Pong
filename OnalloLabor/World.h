#pragma once

#include "defs.h"

#include "Delta.h"

#include "Player.h"
#include "PlayerCPU.h"
#include "Ball.h"
#include <array>
#include <iostream>
#include <vector>
class World
{
private:


	std::array<Entity*, 2> players =
	{
		new Player({CONFIG::paddle_w,CONFIG::paddle_h },{CONFIG::left_paddle::x,CONFIG::left_paddle::y}),
		new PlayerCPU({CONFIG::paddle_w,CONFIG::paddle_h},{CONFIG::right_paddle::x,CONFIG::right_paddle::y})
	};
	
	std::vector<Entity*> balls =
	{
		new Ball({ CONFIG::ball::w,CONFIG::ball::h }, { CONFIG::ball::x,CONFIG::ball::y })
	};

public:

	

	std::array<Entity*, 2> &getPlayers();
	std::vector<Entity*> getBalls();
	void UpdateEntities();

};

