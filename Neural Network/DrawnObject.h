#pragma once

#include "Position.h"
#include <SFML\Graphics.hpp>

class DrawnObject
{
public:
	virtual void tick(sf::RenderWindow* window) = 0;
protected:
	Position pos;
};
