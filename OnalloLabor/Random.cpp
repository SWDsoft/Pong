#include "Random.h"

int Random::getRandom(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}



std::shared_ptr <Random>
Random::getInstance()
{
	if (instance == nullptr)
	{
		instance = std::shared_ptr<Random>(new Random);
	}
	return instance;
}

std::shared_ptr<Random> Random::instance = 0;
