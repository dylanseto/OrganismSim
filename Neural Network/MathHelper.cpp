#include "MathHelper.h"
#include "Agent.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>

float MathHelper::RandomNumberClamped()
{
	float x = rand() % 100 - 100;
	return x / 100;//rand() % 10 + 1;
}

float MathHelper::sigmoid(float num)
{
	//tanh(num);
	return (1 / pow(exp(1.0), -1 * (num))); 
}

bool MathHelper::agentIntersection(Position pos1, Position pos2)
{
	/*if (   pos1.x + Agent::AGENT_RADIUS > pos2.x - Agent::AGENT_RADIUS
		|| pos2.x + Agent::AGENT_RADIUS > pos1.x - Agent::AGENT_RADIUS
		|| pos1.y + Agent::AGENT_RADIUS > pos2.y - Agent::AGENT_RADIUS
		|| pos2.y + Agent::AGENT_RADIUS > pos1.y - Agent::AGENT_RADIUS)
	{
		return true;
	}*/
	if (sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2)) < 25)
	{
		return true;
	}
	return false;
}
