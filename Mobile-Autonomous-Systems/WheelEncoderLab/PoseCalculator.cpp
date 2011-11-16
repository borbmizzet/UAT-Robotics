#include "PoseCalculator.h"


Pose PoseCalculator::CalculateNewExactPose(Pose initialPose, Wheel leftWheel, Wheel rightWheel,
		int accumulatedTicksOnLeftWheel, int accumulatedTicksOnRightWheel, double timePassedSinceLastCheck,
		double distanceBetweenWheels)
{
	Pose newPose;
	double leftWheelVelocity;
	double rightWheelVelocity;

	leftWheelVelocity = CalculateWheelVelocity(leftWheel, accumulatedTicksOnLeftWheel, timePassedSinceLastCheck);
	rightWheelVelocity = CalculateWheelVelocity(rightWheel, accumulatedTicksOnRightWheel, timePassedSinceLastCheck);

	newPose.location.x = CalculateNewExactXLocation(initialPose, leftWheelVelocity, rightWheelVelocity,
		timePassedSinceLastCheck, distanceBetweenWheels);
	newPose.location.y = CalculateNewExactYLocation(initialPose, leftWheelVelocity, rightWheelVelocity,
		timePassedSinceLastCheck, distanceBetweenWheels);
	newPose.headingInRadians = CalculateNewExactHeading(initialPose, leftWheelVelocity, rightWheelVelocity,
		timePassedSinceLastCheck, distanceBetweenWheels);

	return newPose;
}

double PoseCalculator::CalculateWheelVelocity(Wheel wheel, int accumulatedTransitionsSinceLastCheck,
		double timePassedSinceLastCheck)
{
	double wheelDisplacementSinceLastCheck;
	wheelDisplacementSinceLastCheck = CalculateWheelDisplacement(wheel, accumulatedTransitionsSinceLastCheck);

	double wheelVelocity;
	wheelVelocity = wheelDisplacementSinceLastCheck / timePassedSinceLastCheck;

	return wheelVelocity;
}

double PoseCalculator::CalculateWheelDisplacement(Wheel wheel, int accumulatedTransitionsSinceLastCheck)
{
	double wheelDisplacement;
	wheelDisplacement = ((2 * PI * wheel.radius) 
		/ wheel.totalNumberOfTransitions)
		* accumulatedTransitionsSinceLastCheck;
	
	return wheelDisplacement;
}

double PoseCalculator::CalculateNewExactYLocation(Pose initialPose, double leftWheelVelocity, double rightWheelVelocity, 
		double timePassedSinceLastCheck, double distanceBetweenWheels)
{
	double newYLocation;

	newYLocation = initialPose.location.y + 
		( (distanceBetweenWheels * (rightWheelVelocity + leftWheelVelocity))
		/ (2 * (rightWheelVelocity - leftWheelVelocity)) )
		* ( cos(((rightWheelVelocity - leftWheelVelocity) * timePassedSinceLastCheck / distanceBetweenWheels) + initialPose.headingInRadians)
		- cos(initialPose.headingInRadians) );

	return newYLocation;
}

double PoseCalculator::CalculateNewExactXLocation(Pose initialPose, double leftWheelVelocity, double rightWheelVelocity, 
		double timePassedSinceLastCheck, double distanceBetweenWheels)
{
	double newXLocation;

	newXLocation = initialPose.location.x + 
		( (distanceBetweenWheels * (rightWheelVelocity + leftWheelVelocity))
		/ (2 * (rightWheelVelocity - leftWheelVelocity)) )
		* ( sin(((rightWheelVelocity - leftWheelVelocity) * timePassedSinceLastCheck / distanceBetweenWheels) + initialPose.headingInRadians)
		- sin(initialPose.headingInRadians) );
	
	return newXLocation;
}

double PoseCalculator::CalculateNewExactHeading(Pose initialPose, double leftWheelVelocity, double rightWheelVelocity,
		double timePassedSinceLastCheck, double distanceBetweenWheels)
{
	double newHeading;

	newHeading = ( ((rightWheelVelocity - leftWheelVelocity) * timePassedSinceLastCheck)
		/ distanceBetweenWheels )
		+ initialPose.headingInRadians;

	return newHeading;
}
