#pragma once

#include "Agent.h"
#include "Food.h"

#include <vector>
#include <SFML/Graphics.hpp>

class World
{
public:
	World();
	void init();
	
	void removeAgent(Agent* agent);

	static World* getInstance();
private:
	vector<Agent*> agents;
	sf::RenderWindow* window;

	void tick();

	int numAgents;
	int test;

	vector<Food*> foods;

	static World* instance;
};