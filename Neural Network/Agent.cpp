#include "Agent.h"
#include <iostream>
using namespace std;

Agent::Agent(Position& pos)
{
	this->AgentBrain = new Brain(); // Create Randomly Generated Brain
	this->fullness = 100;
	this->sDeltaTime = 0;

	//Make Random
	this->pos = Position(pos.x, pos.y);
}

Agent::Agent() : Agent(Position(5, 5))
{
}

void Agent::tick(sf::RenderWindow * window)
{
	//Brain Calculation
	vector<float> input;
	input.push_back(pos.x / 800);
	input.push_back(pos.y / 800);
	input.push_back(this->fullness / 120);
	input.push_back(1);

	//cout << "in: " << pos.y / 800 - 0.5 << endl;

	vector<float> out = AgentBrain->update(input);

	/*for (int i = 0; i != out.size(); i++)
	{
		cout << out[i] << endl;
	}
	cout << "----" << endl;
*/
	deltaTime = deltaClock.restart();
	sDeltaTime += deltaTime.asSeconds();

	if (sDeltaTime > 2)
	{
		this->fullness -= 30;

		sDeltaTime = 0;
	}
	//Update Position Based on input
	float vx = out[0] - 0.5;
	float vy = out[1] - 0.5;
	pos.x = pos.x + 2 * vx;
	pos.y = pos.y + 2 * vy;

	/*cout << "vx: " << vx << endl;
	cout << "vy: " << vy << endl;*/

	//Draw result with SFML
	sf::CircleShape circle;
	circle.setRadius(25);
	//circle.setOutlineColor(sf::Color::Red);
	circle.setFillColor(sf::Color::Red);
	//circle.setOutlineThickness(5);
	circle.setPosition(pos.x, pos.y);

	window->draw(circle);
}
