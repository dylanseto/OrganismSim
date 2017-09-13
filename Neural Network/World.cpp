#include "World.h"
#include "MathHelper.h"

#include <SFML/Graphics.hpp>

World::World()
{
	srand(time(NULL));
	while(this->agents.size() != 5)
	{
		float x = rand() % (SCREEN_WIDTH - Agent::AGENT_RADIUS) - Agent::AGENT_RADIUS;
		float y = rand() % (SCREEN_HEIGHT - Agent::AGENT_RADIUS) - Agent::AGENT_RADIUS;

		Position pos(x, y);

		bool intersect = false;
		for (Agent * agent : this->agents)
		{
			//agent->getPos()
			if (MathHelper::agentIntersection(pos, agent->getPos()))
			{
				intersect = true;
				break;
			}
		}
		if (!intersect)
		{
			this->agents.push_back(new Agent(pos));
		}
	}
}

void World::init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Organism Simulator");

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

	for (Agent* agent : agents)
	{
		agent->tick(this->window);
	}
	window->display();
}

World* World::instance = nullptr;

World* World::getInstance()
{
	if (instance == nullptr) instance = new World();
	return instance;
}
