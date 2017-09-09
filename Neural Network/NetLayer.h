#pragma once

#include "Neuron.h"
#include <vector>
using namespace std;

class NetLayer
{
private:
	vector<Neuron*> neurons;
public:
	NetLayer();
	NetLayer(vector<Neuron*> neurons);
	vector<float> update(vector<float> inputs);

	int neuronCount() { return this->neurons.size(); }
};
