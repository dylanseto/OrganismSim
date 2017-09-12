#pragma once

#include "Brain.h"
#include "Position.h"
#include <SFML\Graphics.hpp>

class Agent
{
public:
	Agent(Position& pos);
	Agent();

	void tick(sf::RenderWindow* window);
private:
	Brain* AgentBrain;
	Position pos;
	
	float fullness; //If this reaches 0 or exceeds 120, Agent dies.
};