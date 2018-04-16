#pragma once

#include "Position.h"
#include <SFML\Graphics.hpp>

class Food
{
public:
	Food();
	Food(Position &pos);
private:
	Position pos;
};
