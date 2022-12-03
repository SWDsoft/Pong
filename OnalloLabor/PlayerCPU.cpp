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
	if (balls[0]->getPosition().x > 300)
	{
		/*int cpuBottomPosition = position.y + (CONFIG::paddle_h);
		int cpuTopPosition = position.y;
		int ballBottomPosition = balls[0]->getPosition().y + (CONFIG::ball::h);
		int ballTopPosition = balls[0]->getPosition().y;
		*/
		int ballCenter = balls[0]->getPosition().y + (CONFIG::ball::h) / 2;
		int cpuCenter = getPosition().y + (CONFIG::paddle_h) / 2;

		if (!InRangeTop())
		{
			setPosition(sf::Vector2f{ position.x, 1 });
			speed = 0;
		}
		else if (!InRangeBottom())
		{
			setPosition(sf::Vector2f{ position.x,(CONFIG::screen::h - CONFIG::paddle_h) - 1 });
			speed = 0;
		}
		else
		{
			if (cpuCenter < ballCenter)//if ball is lower
			{
				if (speed < maxSpeed)
				{
					if (speed < 0)
						speed += acceleration * 3 * Delta::getInstance()->getDelta();
					else
						speed += acceleration * Delta::getInstance()->getDelta();
				}
				else
				{
					speed = maxSpeed;
				}


				currentDirection = 1;
			}
			else if (cpuCenter > ballCenter)//if ball is higher
			{
				if (speed > (-1) * maxSpeed)
				{
					if (speed > 0)
						speed -= acceleration * 3 * Delta::getInstance()->getDelta();
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
	else speed = 0;
	
}

void
PlayerCPU::addScore()
{
	score++;
}