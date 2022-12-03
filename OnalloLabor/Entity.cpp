#include "Entity.h"

#include "defs.h"

Entity::Entity(sf::Vector2f dim, sf::Vector2f pos)
{
	DEBUG(position.x);
	body = sf::RectangleShape({dim.x,dim.y});
	position = pos;
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
