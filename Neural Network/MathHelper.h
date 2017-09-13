#pragma once

#include "Position.h"

namespace MathHelper
{
	float RandomNumberClamped();
	float sigmoid(float num);
	bool agentIntersection(Position pos1, Position pos2);
}