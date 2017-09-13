#pragma once

#include "Agent.h"

#include <vector>
#include <SFML/Graphics.hpp>

class World
{
public:
	World();
	void init();

	static World* getInstance();
private:
	vector<Agent*> agents;
	sf::RenderWindow* window;

	void tick();
	static World* instance;
	const int SCREEN_HEIGHT = 700;
	const int SCREEN_WIDTH = 700;
};