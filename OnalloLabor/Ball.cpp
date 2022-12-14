#include "Ball.h"


void
Ball::ballInit()
{


	int random = Random::getInstance()->getRandom(1,200);

	wallPopCount = 0;
	lifeTime = 0;
	speed_x = Random::getInstance()->getRandom(CONFIG::ball::min_speed, CONFIG::ball::max_speed);
	speed_y = Random::getInstance()->getRandom(CONFIG::ball::min_speed, CONFIG::ball::max_speed);

	DEBUG(speed_x);
	DEBUG(speed_y);

	if (random >= 0 && random < 50)
	{
		dir_x = 1;
		dir_y = 1;
	}
	else if (random >= 50 && random < 100)
	{
		dir_x = -1;
		dir_y = 1;
	}
	else if (random >= 100 && random < 150)
	{
		dir_x = 1;
		dir_y = -1;
	}
	else if (random >= 150 && random < 200)
	{
		dir_x = -1;
		dir_y = -1;
	}


}

bool
Ball::AddBall()
{
	if (wallPopCount >= CONFIG::ball::spawn_afterPop)
	{
		wallPopCount = 0;
		return true;
	}
	else
	{
		return false;
	}
}

void
Ball::checkSides(std::array<Entity*, 2> players)
{

	if (AABB::AABBSide(getPosition(), players[0]->getPosition()) || AABB::AABBSide(getPosition(), players[1]->getPosition()))
	{
		dir_x *= -1;
	}
	else
	{
		if (this->getBody().getPosition().x <= 0 )
		{
			dir_x *= -1;

			setPosition({ sf::Vector2f{500,500} });
			ballInit();

			wallPopCount++;
			lifeTime++;

		}

		else if ((this->getBody().getPosition().x + CONFIG::ball::w) >= CONFIG::screen::w)
		{
			dir_x *= -1;

			setPosition({ sf::Vector2f{500,500} });
			ballInit();

			wallPopCount++;
			lifeTime++;
		}

		if (this->getBody().getPosition().y <= 0 )
		{
			dir_y *= -1;

			wallPopCount++;
			lifeTime++;
		}

		else if ((this->getBody().getPosition().y + CONFIG::ball::h) >= CONFIG::screen::h )
		{
			dir_y *= -1;

			wallPopCount++;
			lifeTime++;

		}
	}

	
}

int
Ball::getLifeTime()
{
	return lifeTime;
}

void
Ball::Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls)
{

	sf::Vector2f vec;

	checkSides(players);
	
	/*if (AddBall())
	{
		balls.push_back(new Ball({ CONFIG::ball::w,CONFIG::ball::h }, { CONFIG::ball::x,CONFIG::ball::y }));
	}*/
	

	vec.x = this->getBody().getPosition().x + (Delta::getInstance()->getDelta() * speed_x * dir_x);
	vec.y = this->getBody().getPosition().y + (Delta::getInstance()->getDelta() * speed_y * dir_y);

	setPosition(vec);
}
