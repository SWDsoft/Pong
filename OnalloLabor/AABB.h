#include "SFML/Graphics.hpp"
#include "defs.h"
#pragma once

namespace AABB
{
	static bool AABBSide(sf::Vector2f a, sf::Vector2f b)
	{
		return (
			a.x < b.x + CONFIG::paddle_w &&
			b.x < a.x + CONFIG::paddle_w &&
			a.y < b.y + CONFIG::paddle_h &&
			b.y < a.y + CONFIG::paddle_h
		);
	}
};