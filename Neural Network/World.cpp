#include "World.h"

#include <SFML/Graphics.hpp>
#include <iostream>

World::World()
{
	this->agents.push_back(new Agent(Position(400, 400)));
	numAgents = 1;
	test = 0;
}

void World::init()
{
this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Organism Simulator");
	while (window->isOpen())
	{
		//sf::Event event;
		//while (window->pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		window->close();
		//}

		//window->clear();
		////window.draw(shape);
		//window->display();

		tick();
	}
}

void World::tick()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	window->clear(sf::Color(255,255,255,255));
	//window.draw(shape);

	if (numAgents > 0)
	{
		for (int i = 0; i!= agents.size(); i++)
		{
			if (agents.size() == 0) break;

			Agent* agent = agents[i];

			if (agent == nullptr) continue; 

			if (agent->getFullness() <= 0 || agent->getFullness() >= 120)
			{
				removeAgent(agent);
				numAgents = numAgents - 1;
			}
			else
			{
				agent->tick(this->window);
			}
		}
	}
	window->display();
}

void World::removeAgent(Agent* agent)
{
	cout << "but" << endl;
	for(int i = 0; i != agents.size(); i++)
	{
		if (agents[i] == agent)
		{
			agents.erase(agents.begin() + i);
			cout << "done" << endl;
			return;
		}
	}
	cout << "done" << endl;
}

World* World::instance;
World * World::getInstance()
{
	if (instance == nullptr) instance = new World();

	return instance;
}
