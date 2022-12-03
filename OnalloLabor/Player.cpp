#include "Player.h"
#include "defs.h"


void
Player::Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls)
{

	int dir = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (speed < maxSpeed)
			speed += acceleration * Delta::getInstance()->getDelta();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if(speed > (-1)*maxSpeed)
			speed -= acceleration * Delta::getInstance()->getDelta();
	}
	else
	{
		speed = 0;
	}

	sf::Vector2f vec;

	if (getPosition().y < 0)
	{
		speed *= -1;
	}
	else if (getPosition().y + CONFIG::paddle_h > CONFIG::screen::h)
	{
		speed *= -1;
	}
	
	vec.y = getPosition().y + (speed * Delta::getInstance()->getDelta());
	vec.x = getPosition().x;
	


	setPosition(vec);


}

void
Player::addScore()
{
	score++;
}