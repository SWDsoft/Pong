#include "Delta.h"
#include <iostream>

float
Delta::getDelta()
{
	return dt.asSeconds();
}

void
Delta::restartClock()
{
	dt = timer.restart();

}


std::shared_ptr <Delta>
Delta::getInstance()
{
	if (instance == nullptr)
	{
		instance = std::shared_ptr<Delta>(new Delta);
	}
	return instance;
}

std::shared_ptr<Delta> Delta::instance = 0;