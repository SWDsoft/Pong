#include "PlayerCPU.h"

bool 
PlayerCPU::InRangeTop() const
{
	return position.y > 0;
}

bool
PlayerCPU::InRangeBottom() const
{
	return position.y + CONFIG::paddle_h < CONFIG::screen::h;
}

void
PlayerCPU::Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls)
{
	int cpuBottomPosition = position.y + (CONFIG::paddle_h);
	int cpuTopPosition = position.y;
	int ballBottomPosition = balls[0]->getPosition().y + (CONFIG::ball::h);
	int ballTopPosition = balls[0]->getPosition().y;

	if (!InRangeTop())
	{
		setPosition(sf::Vector2f{position.x, 1});
		speed = 0;
	}
	else if(!InRangeBottom())
	{
		setPosition(sf::Vector2f{ position.x,(CONFIG::screen::h - CONFIG::paddle_h) - 1});
		speed = 0;
	}
	else
	{ 
		if ( cpuBottomPosition < ballBottomPosition  )//if ball is lower
		{
			if (speed < maxSpeed)
			{
				if(speed < 0)
					speed += acceleration * 10 * Delta::getInstance()->getDelta();
				else
					speed += acceleration * Delta::getInstance()->getDelta();
			}
			else
			{
				speed = maxSpeed;
			}
						

			currentDirection = 1;
		}
		else if ( cpuTopPosition >= ballTopPosition )//if ball is higher
		{
			if (speed > (-1) * maxSpeed)
			{
				if (speed > 0)
					speed -= acceleration * 10 * Delta::getInstance()->getDelta();
				else
					speed -= acceleration * Delta::getInstance()->getDelta();
			}
			else
			{
				speed = -maxSpeed;
			}

			currentDirection = -1;
		}
	}

	setPosition(sf::Vector2f{ position.x, position.y + speed * Delta::getInstance()->getDelta() });
}