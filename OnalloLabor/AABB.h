#include "SFML/Graphics.hpp"
#include "defs.h"
#pragma once

namespace AABB
{
	static bool AABBSide(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& a_size, const sf::Vector2f& b_size)
	{
		return (
			a.x < b.x + b_size.x &&
			b.x < a.x + a_size.x &&
			a.y < b.y + b_size.y &&
			b.y < a.y + a_size.y
		);
	}
};