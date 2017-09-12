#pragma once

#include "Agent.h"
#include <vector>

class World
{
public:
	World();
	void init();
	void tick();
private:
	vector<Agent*> agents;
};