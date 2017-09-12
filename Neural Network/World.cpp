#include "World.h"

#include <SFML/Graphics.hpp>

World::World()
{
}

void World::init()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Organism Simulator");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(shape);
		window.display();
	}
}