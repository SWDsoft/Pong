#include "PlayerCPU.h"

bool 
PlayerCPU::InRangeTop() const
{
	return this->getBody().getPosition().y > 0;
}

bool
PlayerCPU::InRangeBottom() const
{
	return this->getBody().getPosition().y + CONFIG::paddle_h < CONFIG::screen::h;
}

void
PlayerCPU::Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls)
{
	 
		
			int cpuBottomPosition = this->getBody().getPosition().y + (CONFIG::paddle_h);
			int cpuTopPosition = this->getBody().getPosition().y;
			int ballBottomPosition = balls[0]->getPosition().y + (CONFIG::ball::h);
			int ballTopPosition = balls[0]->getPosition().y;

			if (!InRangeTop())
			{
				setPosition(sf::Vector2f{getPosition().x,1});
			}
			else if(!InRangeBottom())
			{
				setPosition(sf::Vector2f{ getPosition().x,(CONFIG::screen::h - CONFIG::paddle_h)-1});
			}
			else
			{ 
				if ( cpuBottomPosition < ballBottomPosition  )//if ball is lower
				{
					if (speed < maxSpeed)
					{
						if(speed < 0)
							speed += acceleration*10 * Delta::getInstance()->getDelta();
						else
							speed += acceleration * Delta::getInstance()->getDelta();
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

					currentDirection = -1;
				}
			}
			
			

		


		this->setPosition(sf::Vector2f{ this->getBody().getPosition().x,this->getBody().getPosition().y + speed * Delta::getInstance()->getDelta() });

}