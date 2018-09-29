#include "Food.h"

Food::Food()
{
	this->pos = Position(0, 0);
}

Food::Food(Position &pos)
{
	this->pos = pos;
}

void Food::tick(sf::RenderWindow * window)
{
}
