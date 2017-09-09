#include "Brain.h"
#include "Neuron.h"

/*
Creates a randomly generated brain, uses Multilevel perceptron.
*/
Brain::Brain()
{
	//Input Layer
	Neuron* smellIntensity = new Neuron();
	Neuron* smellPositionX = new Neuron();
	Neuron* smellPositionY = new Neuron();
	Neuron* hungerDetect = new Neuron();

	vector<Neuron*> inputNeurons;
	inputNeurons.push_back(smellIntensity);
	inputNeurons.push_back(smellPositionX);
	inputNeurons.push_back(smellPositionY);
	inputNeurons.push_back(hungerDetect);

	this->inputLayer = new NetLayer(inputNeurons);

	//Hidden Layer
	vector<Neuron*> hiddenNeurons;

	for (int i = 0; i != HIDDEN_NEUR_COUNT; i++)
	{
		hiddenNeurons.push_back(new Neuron(this->inputLayer->neuronCount()));
	}

	this->hiddenLayer = new NetLayer(hiddenNeurons);

	//Output Layer

	Neuron* leftWheel = new Neuron();
	Neuron* rightWheel = new Neuron();
}

vector<float> Brain::update(vector<float> input)
{
	//input layer is not used for now, we don't want signoid to be used.

	vector<float> hiddenOut = hiddenLayer->update(input);
	vector<float> out = outputLayer->update(input);

	return vector<float>();
}