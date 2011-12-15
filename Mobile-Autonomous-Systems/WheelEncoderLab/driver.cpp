//TODO: Driver program, Comparison functions between Exact and approximate calculations
#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"
#include "Pose.h"
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

		/*
		sourceFile >> distance;
		sourceFile.ignore(2, '\t');
		sourceFile >> angle;
		sourceFile.ignore(2,'\n');
		

		
		destinationFile.precision(10);
		destinationFile << distance << '\t' << angle << '\t';
		destinationFile.precision(6);
		destinationFile << robotFrame.x << '\t'
			<< robotFrame.y << '\t' << worldFrame.x << '\t' << worldFrame.y << '\n' ;
*/
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
	int leftTicks;
	int leftDirection;
	int rightTicks;
	int rightDirection;
	int time;

	resetPose(currentPose);

	sourceFile.ignore(256, '\n');

	exactFile << "Time\t" << "Exact_X\t" << "Exact_Y\t" << "Exact_Heading\n";
	while (!sourceFile.eof())
	{

	}
	sourceFile.close();
	exactFile.close();

}
void approximateCalculations(double distanceBetweenWheels, Wheel bothWheels, Pose currentPose)
{
	ifstream sourceFile("EncoderData.txt", ios::in);
	ofstream approximateFile("ApproximateData.txt", ios::out);
	int leftTicks;
	int leftDirection;
	int rightTicks;
	int rightDirection;
	int time;
	resetPose(currentPose);

	sourceFile.ignore(256, '\n');

	approximateFile << "Time\t" << "Approx_X\t" << "Approx_Y\t"
			<< "Approx_Heading\n";
	while (!sourceFile.eof())
	{

	}
	sourceFile.close();
	approximateFile.close();
}
