#pragma once

#include "sfml/Graphics.hpp"

class Delta
{

private:

	 sf::Clock timer;
	 sf::Time dt;

	 static std::shared_ptr < Delta > instance;

	 Delta() {}

public:

	static std::shared_ptr < Delta > getInstance();

	float getDelta();
	void restartClock();

};
