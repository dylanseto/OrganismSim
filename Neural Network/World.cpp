#include "World.h"

#include <SFML/Graphics.hpp>

World::World()
{
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
	window->display();
}
