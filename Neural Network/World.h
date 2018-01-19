#pragma once

#include "Agent.h"

#include <vector>
#include <SFML/Graphics.hpp>

class World
{
public:
	World();
	void init();
	
	void removeAgent(Agent* agent);
private:
	vector<Agent*> agents;
	sf::RenderWindow* window;

	void tick();

	int numAgents;
	int test;
};