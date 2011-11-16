#ifndef SENSEDPOINTCALCULATOR_H
#define SENSEDPOINTCALCULATOR_H

#pragma once

#include <cmath>
using std::sin;
using std::cos;
#include "Point.h"
#include "Pose.h"

class SensedPointCalculator
{
public:

	static Point CalculateCoordinatesOfSensedPointInWorldFrame(Point sensedCoordinatesInRobotFrame, Pose currentPose);
	static Point CalculateCoordinatesOfSensedPointInRobotFrame(double angleSensedInRadians, double distanceSensed);	
};
#endif
