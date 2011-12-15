#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"
#include "Pose.h"
#include "SensedPointCalculator.h"

void printHeader(ofstream & destinationFile);

int main(void)
{
	ifstream sourceFile("SenseData.txt", ios::in);
	ofstream destinationFile("ResultData.txt", ios::out);
	
	Pose givenPose;
	givenPose.location.x = 12;
	givenPose.location.y = 4;
	givenPose.headingInRadians = -0.7854;
	

	sourceFile.ignore(256, '\n');

	printHeader(destinationFile);
	while (!sourceFile.eof())
	{
		double distance;
		double angle;
		Point worldFrame;
		Point robotFrame;
		
		sourceFile >> distance;
		sourceFile.ignore(2, '\t');
		sourceFile >> angle;
		sourceFile.ignore(2,'\n');
		
		robotFrame = SensedPointCalculator::CalculateCoordinatesOfSensedPointInRobotFrame(angle, distance);
		worldFrame = SensedPointCalculator::CalculateCoordinatesOfSensedPointInWorldFrame(robotFrame, givenPose);
		
		destinationFile.precision(10);
		destinationFile << distance << '\t' << angle << '\t';
		destinationFile.precision(6);
		destinationFile << robotFrame.x << '\t'
			<< robotFrame.y << '\t' << worldFrame.x << '\t' << worldFrame.y << '\n' ;

	}
	sourceFile.close();
	destinationFile.close();

	return 0;
}
void printHeader(ofstream & destinationFile)
{

	destinationFile << "D_sense\t" << "Theta_sense\t" << "Px_robot\t"
		<< "Py_robot\t" << "Px_world\t" << "Py_world\n";

}
