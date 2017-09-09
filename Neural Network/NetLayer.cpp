#include "NetLayer.h"
#include "MathHelper.h"

NetLayer::NetLayer()
{
	this->neurons.push_back(new Neuron());
}

NetLayer::NetLayer(vector<Neuron*> neurons)
{
	this->neurons = neurons;
}

vector<float> NetLayer::update(vector<float> input)
{
	vector<float> out;

	for (int i = 0; i != this->neurons.size(); i++)
	{
		Neuron* cur = this->neurons[i];

		if (cur->getWeights().size() != input.size()) //Don't Match
		{
			return vector<float>();
		}

		for (int j = 0; j != cur->getWeights().size(); j++)
		{
			float act = cur->getWeights()[i] * input[i];

			out.push_back(MathHelper::sigmoid(act));
		}
	}
	return out;
}
