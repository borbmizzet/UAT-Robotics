//TODO: Comparison functions between Exact and approximate calculations
#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"
#include "Pose.h"
#include "Wheel.h"
#include "PoseCalculator.h"

void exactCalculations(double distanceBetweenWheels, Wheel bothWheels, Pose currentPose);
void approximateCalculations(double distanceBetweenWheels, Wheel bothWheels, Pose currentPose);
void resetPose(Pose & currentPose);


int main(void)
{
	double distanceBetweenWheels = 300;
	Wheel bothWheels;
	Pose currentPose;
	
	bothWheels.radius = 20;
	bothWheels.totalNumberOfTransitions = 64;
	
	exactCalculations(distanceBetweenWheels, bothWheels, currentPose);
	approximateCalculations(distanceBetweenWheels, bothWheels, currentPose);

	return 0;
}
void resetPose(Pose & currentPose)
{
	currentPose.location.x = 0;
	currentPose.location.y = 0;
	currentPose.headingInRadians = 0;
}
void exactCalculations(double distanceBetweenWheels, Wheel bothWheels, Pose currentPose)
{
	ifstream sourceFile("EncoderData.txt", ios::in);
	ofstream exactFile("ExactData.txt", ios::out);
	int leftTicks = 0;
	int leftDirection = 1;
	int rightTicks = 0;
	int rightDirection = 1;
	int currentTime = 0;
	int lastTime = 0;


	resetPose(currentPose);

	sourceFile.ignore(256, '\n');

	exactFile << "Time\t" << "Exact_X\t" << "Exact_Y\t" << "Exact_Heading\n";
	while (!sourceFile.eof())
	{
		exactFile << currentTime << '\t' << currentPose.location.x << '\t' << currentPose.location.y << '\t' << currentPose.headingInRadians << '\n';
		lastTime = currentTime;

		sourceFile >> leftTicks;
		sourceFile.ignore(2, '\t');
		sourceFile >> leftDirection;
		sourceFile.ignore(2, '\t');
		sourceFile >> rightTicks;
		sourceFile.ignore(2, '\t');
		sourceFile >> rightDirection;
		sourceFile.ignore(2, '\t');
		sourceFile >> currentTime;
		sourceFile.ignore(2, '\n');

		currentPose = PoseCalculator::CalculateNewExactPose(currentPose, bothWheels, bothWheels, leftTicks * leftDirection, rightTicks * rightDirection, currentTime - lastTime, distanceBetweenWheels);


	}
	sourceFile.close();
	exactFile.close();

}
void approximateCalculations(double distanceBetweenWheels, Wheel bothWheels, Pose currentPose)
{
	ifstream sourceFile("EncoderData.txt", ios::in);
	ofstream approximateFile("ApproximateData.txt", ios::out);
	int leftTicks = 0;
	int leftDirection = 1;
	int rightTicks = 0;
	int rightDirection = 1;
	int currentTime = 0;
	int lastTime = 0;

	resetPose(currentPose);

	sourceFile.ignore(256, '\n');

	approximateFile << "Time\t" << "Approx_X\t" << "Approx_Y\t"
			<< "Approx_Heading\n";
	while (!sourceFile.eof())
	{
		approximateFile << currentTime << '\t' << currentPose.location.x << '\t' << currentPose.location.y << '\t' << currentPose.headingInRadians << '\n';
		lastTime = currentTime;

		sourceFile >> leftTicks;
		sourceFile.ignore(2, '\t');
		sourceFile >> leftDirection;
		sourceFile.ignore(2, '\t');
		sourceFile >> rightTicks;
		sourceFile.ignore(2, '\t');
		sourceFile >> rightDirection;
		sourceFile.ignore(2, '\t');
		sourceFile >> currentTime;
		sourceFile.ignore(2, '\n');

		currentPose = PoseCalculator::CalculateNewApproximatePose(currentPose, bothWheels, bothWheels, leftTicks * leftDirection, rightTicks * rightDirection, distanceBetweenWheels);
	}
	sourceFile.close();
	approximateFile.close();
}
