#ifndef POSECALCULATOR_H
#define POSECALCULATOR_H

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>
using std::sin;
using std::cos;
#ifndef PI
#define PI M_PI
#endif

#include "Point.h"
#include "Pose.h"
#include "Wheel.h"

class PoseCalculator
{
public:

	static Pose CalculateNewExactPose(Pose initialPose, Wheel leftWheel, Wheel rightWheel,
		int accumulatedTicksOnLeftWheel, int accumulatedTicksOnRightWheel, double timePassedSinceLastCheck,
		double distanceBetweenWheels);

private:	

	static double CalculateWheelVelocity(Wheel wheel, int accumulatedTicksSinceLastCheck,
		double timePassedSinceLastCheck);
		
	static double CalculateWheelDisplacement(Wheel wheel, int accumulatedTicksSinceLastCheck);
	
	static double CalculateNewExactYLocation(Pose initialPose, double leftWheelVelocity, double rightWheelVelocity, 
		double timePassedSinceLastCheck, double distanceBetweenWheels);
	
	static double CalculateNewExactXLocation(Pose initialPose, double leftWheelVelocity, double rightWheelVelocity, 
		double timePassedSinceLastCheck, double distanceBetweenWheels);
	
	static double CalculateNewExactHeading(Pose initialPose, double leftWheelVelocity, double rightWheelVelocity,
		double timePassedSinceLastCheck, double distanceBetweenWheels);	
	
	//TODO: Approximation Functions for microcontrollers, Driver program, Comparison functions between Exact and approximate calculations
};
#endif
