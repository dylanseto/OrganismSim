#pragma once

struct Position
{
	Position()
	{
		this->x = 0;
		this->y = 0; 
	}
	Position(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	float x;
	float y;
};
