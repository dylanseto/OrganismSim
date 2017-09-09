#pragma once

#include "Brain.h"

class Agent
{
public:
	Agent();

	void tick();
private:
	Brain* AgentBrain;

	float fullness; //If this reaches 0 or exceeds 120, Agent dies.
};