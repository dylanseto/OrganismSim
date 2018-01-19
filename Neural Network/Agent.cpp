#include "Agent.h"
#include <iostream>
using namespace std;

Agent::Agent(Position& pos)
{
	this->AgentBrain = new Brain(); // Create Randomly Generated Brain
	this->fullness = 100;
	this->sDeltaTime = 0;

	this->pos = Position(pos.x, pos.y);
}

Agent::Agent() : Agent(Position(0, 0))
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
	//Update Position Based on output
	float w_r = out[0];
	float w_l = out[1];
	
	//(1,1) right wheel
	//(1,-1) left wheel
	//^ Rotate these
	float w_r_x = -1 * w_r;
	float w_r_y = 1 * w_r;
	float w_l_x = 1 * w_l;
	float w_l_y = -1 * w_l;

	pos.x = pos.x + w_r_x + w_l_x;
	pos.y = pos.y + w_r_y + w_l_y;

	cout << "vx: " << pos.x << endl;
	cout << "vy: " << pos.y << endl;

	//Draw result with SFML
	sf::CircleShape circle;
	circle.setRadius(25);
	//circle.setOutlineColor(sf::Color::Red);
	circle.setFillColor(sf::Color::Red);
	//circle.setOutlineThickness(5);
	circle.setPosition(pos.x, pos.y);

	sf::RectangleShape rec;
	rec.setSize(sf::Vector2f(2, 50));
	rec.setFillColor(sf::Color::Black);
	rec.setPosition(pos.x+25, pos.y-25);
	//rec.setRotation(0);

	sf::Transform transform;
	transform.rotate(180, sf::Vector2f(pos.x, pos.y));//sf::Vector2f(pos.x + 25, pos.y - 25));

	window->draw(circle);
	window->draw(rec, transform);
}
