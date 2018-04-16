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
	if (inputWeights.size() != inputNum)
	{
		throw "Unmatched Input Numbers in Neurons";
	}
	this->inputNum = inputNum;
	this->inputWeights = inputWeights;
}

void Neuron::setWeightByIndex(int i, float v)
{
	this->inputWeights[i] = v;
}
