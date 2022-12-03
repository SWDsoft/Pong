#pragma once

#include "sfml/Graphics.hpp"

class Entity
{

private:	

	sf::Vector2f position;
	sf::RectangleShape body;

public:
	
	Entity(sf::Vector2f dim, sf::Vector2f pos);
	void setPosition(sf::Vector2f pos);
	const sf::Vector2f& getPosition() const;
	const sf::RectangleShape& getBody() const;

	virtual void Control(std::array<Entity*, 2> players, std::vector<Entity*> &balls) = 0;
};

