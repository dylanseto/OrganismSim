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

	Position getPos() { return pos; }

	static const int AGENT_RADIUS = 25;
private:
	Brain* AgentBrain;
	Position pos;
	
	float fullness; //If this reaches 0 or exceeds 120, Agent dies.
};