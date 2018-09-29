#include "Food.h"

Food::Food()
{
	this->pos = Position(20, 20);
}

Food::Food(Position &pos)
{
	this->pos = pos;
}

void Food::tick(sf::RenderWindow * window)
{
	sf::RectangleShape rec;
	rec.setSize(sf::Vector2f(50, 50));
	rec.setFillColor(sf::Color::Green);
	rec.setPosition(pos.x, pos.y);

	window->draw(rec);
}
