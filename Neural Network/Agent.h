#pragma once

#include "Brain.h"
#include "DrawnObject.h"

class Agent : DrawnObject
{
public:
	Agent(Position& pos);
	Agent();

	void tick(sf::RenderWindow* window);

	float getFullness() { return fullness; }
private:
	Brain* AgentBrain;
	
	float fullness; //If this reaches 0 or exceeds 120, Agent dies.
	sf::Clock deltaClock;
	sf::Time deltaTime;
	float sDeltaTime;
};