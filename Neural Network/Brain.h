#pragma once

#include "NetLayer.h"

class Brain
{
private:
	/*
	Input Layer is composed of:
	2 Smell inputs:
		1) Smell Intensity
		2) Distance
	1 Hunger input, which is inversely proportional to the agent's fullness parameter.
	*/
	NetLayer* inputLayer;
	/*
	Hidden Layer
	Contains 8 Neurons.
	*/
	NetLayer* hiddenLayer;
	int const HIDDEN_NEUR_COUNT = 8;

	/*
	Output Layer is composed
	1) Right Wheel, speed and acceleration
	2) Left Wheel,  speed and acceleration
	*/
	NetLayer* outputLayer;
public:
	Brain();

	vector<float> update(vector<float> input);
};