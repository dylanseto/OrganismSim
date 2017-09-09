#include "Agent.h"
#include <iostream>
using namespace std;

Agent::Agent()
{
	this->AgentBrain = new Brain(); // Create Randomly Generated Brain
	this->fullness = 100;
}

void Agent::tick()
{
	//Brain Calculation
	vector<float> input;
	input.push_back(0.3);
	input.push_back(1);
	input.push_back(1);
	input.push_back(-1);

	vector<float> out = AgentBrain->update(input);

	for (int i = 0; i != out.size(); i++)
	{
		cout << out[i] << endl;
	}

	//draw result with SFML
}
