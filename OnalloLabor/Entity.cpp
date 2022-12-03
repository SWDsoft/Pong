#include "Entity.h"

Entity::Entity(sf::Vector2f dim, sf::Vector2f pos)
{
	body = sf::RectangleShape({dim.x,dim.y});
	body.setPosition(pos);
}

void Entity::setPosition(sf::Vector2f pos)
{
	position = pos;
	body.setPosition(pos);
}

const sf::Vector2f& Entity::getPosition() const
{
	return position;
}


const sf::RectangleShape& Entity::getBody() const
{
	return body;
}
