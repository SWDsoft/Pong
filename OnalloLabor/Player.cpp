#include "Player.h"
#include "defs.h"


void
Player::Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls)
{
	int dir = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dir = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dir = -1;
	}
	else
	{
		dir = 0; 
	}

	sf::Vector2f vec;

	vec.x = getPosition().x;
	vec.y = balls[0]->getPosition().y/*getPosition().y + (dir * Delta::getInstance()->getDelta() * 1500)*/;


	setPosition(vec);


}