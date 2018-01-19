#pragma once

#include <vector>
using namespace std;

class Neuron
{
public:
	Neuron();
	Neuron(float inputNum);
	Neuron(float inputNum, vector<float> inputWeights);

	vector<float> getWeights() {
		return inputWeights;
	}
	void setWeightByIndex(int i, float v);

private:
	vector<float> inputWeights; //weights
	float inputNum;
};