#include "Agent.h"
#include <iostream>
using namespace std;

Agent::Agent(Position& pos)
{
	this->AgentBrain = new Brain(); // Create Randomly Generated Brain
	this->fullness = 100;

	this->pos = Position(pos.x, pos.y);
}

Agent::Agent() : Agent(Position(0, 0))
{
}

void Agent::tick(sf::RenderWindow * window)
{
	//Brain Calculation
	vector<float> input;
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);

	vector<float> out = AgentBrain->update(input);

	/*for (int i = 0; i != out.size(); i++)
	{
		cout << out[i] << endl;
	}*/

	//Update Position Based on input

	//Draw result with SFML
	sf::CircleShape circle;
	circle.setRadius(AGENT_RADIUS);
	//circle.setOutlineColor(sf::Color::Red);
	circle.setFillColor(sf::Color::Red);
	//circle.setOutlineThickness(5);
	circle.setPosition(pos.x, pos.y);

	window->draw(circle);
}
