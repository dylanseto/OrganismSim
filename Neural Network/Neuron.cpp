#include "Neuron.h"
#include "MathHelper.h"

Neuron::Neuron() : Neuron(1)
{
}

Neuron::Neuron(float inputNum)
{
	this->inputNum = inputNum;

	for (int i = 0; i != inputNum; i++)
	{
		this->inputWeights.push_back(MathHelper::RandomNumberClamped());
	}
}

Neuron::Neuron(float inputNum, vector<float> inputWeights)
{
	this->inputNum = inputNum;
	this->inputWeights = inputWeights;
}
