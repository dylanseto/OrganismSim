#pragma once

#include "DrawnObject.h"

class Food : DrawnObject
{
public:
	Food();
	Food(Position &pos);

	void tick(sf::RenderWindow* window);
};
