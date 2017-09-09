#include "MathHelper.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>

float MathHelper::RandomNumberClamped()
{
	float x = rand() % 100 - 100;
	return x / 100;//rand() % 10 + 1;
}

float MathHelper::sigmoid(float num)
{
	return tanh(num);
}
