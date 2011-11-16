#include "SensedPointCalculator.h"

Point SensedPointCalculator::CalculateCoordinatesOfSensedPointInWorldFrame(Point sensedCoordinatesInRobotFrame,  Pose currentPose)
{
	Point worldCentricSensedPoint;

	worldCentricSensedPoint.x = 
		sensedCoordinatesInRobotFrame.x * cos(currentPose.headingInRadians)
		- sensedCoordinatesInRobotFrame.y * sin(currentPose.headingInRadians)
		+ currentPose.location.x;

	worldCentricSensedPoint.y = 
		sensedCoordinatesInRobotFrame.x * sin(currentPose.headingInRadians)
		+ sensedCoordinatesInRobotFrame.y * cos(currentPose.headingInRadians)
		+ currentPose.location.y;
	
	return worldCentricSensedPoint;
}

Point SensedPointCalculator::CalculateCoordinatesOfSensedPointInRobotFrame(double angleSensedInRadians, double distanceSensed)
{
	Point robotCentricSensedPoint;

	robotCentricSensedPoint.x = cos(angleSensedInRadians) * distanceSensed;
	robotCentricSensedPoint.y = sin(angleSensedInRadians) * distanceSensed;
	
	return robotCentricSensedPoint;
}



