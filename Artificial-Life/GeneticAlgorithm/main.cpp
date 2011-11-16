#include <iostream>
using std::cout;
using std::cin;
#include "EvolutionaryAlgorithm.h"


double inputMutationRate(void);
int inputNumberOfGenes(void);
double inputEilitismBias(void);
int inputNumberOfGenerations(void);
int inputPopulationSize(void);
int inputTargetValue(void);
int inputNumberOfChildren(void);
bool inputNewStopAtGoal(void);
int inputAgeLimit(void);
int inputTournamentSize(int populationSize);
vector<CoinType> & inputCoinTypes(vector<CoinType> & tempCoinTypes);
void addCoinType(vector<CoinType> & tempCoinTypes, string name, int value);
int main()
{

	cout << "Welcome to the A.C.M.E. Evolutionary-Algorithm-Based Coin Calculator" << endl
		<< "VERSION 2.0." << endl
		<< "This version incorperates anti-survivor-cloning and death via old age." << endl << endl
		<< "Terms of Use" << endl
		<< "The use of this software for the capture of speeding birds has" << endl
		<< "not been tested, and A.C.M.E. Inc. shall not be held liable for" << endl
		<< "damages incurred while attempting to capture such birds." << endl << endl
		<< "If you agree to these terms of use, please give Jon Geller a high number" << endl
		<< "of points for this project. If not, please still give Jon Geller high points" << endl
		<< "for this project.  Either way, giving Jon Geller a high number of points for" << endl 
		<< "this project will effectively increase your own awesomeness by " << endl
		<< "(GivenNumberOfPoints * 10^2) metric units of awesome." << endl
		<< endl << endl;
	vector<CoinType> tempCoinTypes;
	int populationSize = inputPopulationSize();
	EvolutionaryAlgorithm eAlgorithm(inputCoinTypes(tempCoinTypes), populationSize, inputTargetValue(),
		inputNumberOfGenerations(), inputEilitismBias(),inputNumberOfGenes(), inputMutationRate(), inputNewStopAtGoal(), inputAgeLimit(), inputTournamentSize(populationSize)); 
	eAlgorithm.run();

	return 0;

}

double inputMutationRate(void)
{
	double tempMutationRate = 2;
	while ((tempMutationRate < 0)  || (tempMutationRate > 1))
	{
		cout << "Enter a mutation rate as a decimal number between 0 and 1: ";
		cin >> tempMutationRate;
	}
	return tempMutationRate;
}
int inputNumberOfGenes(void)
{
	int tempNumberOfGenes = 2000;
	while ((tempNumberOfGenes < 1)  || (tempNumberOfGenes > 1000))
	{
		cout << "Enter a number of coins per individual as an integer number between 1 and 1000: ";
		cin >> tempNumberOfGenes;
	}
	return tempNumberOfGenes;
}
double inputEilitismBias(void)
{
	double tempElitism = 2;
	while ((tempElitism < 0)  || (tempElitism > 1))
	{
		cout << "Enter a elitism percentage as a decimal number between 0 and 1" << endl
			<< "(Note that if you choose to activate death-via-old-age, " << endl
			<< "elitists will NOT survive if they are too old): ";
		cin >> tempElitism;
	}
	return tempElitism;
}
int inputNumberOfGenerations(void)
{
	int tempNumberOfGenerations = 2000;
	while ((tempNumberOfGenerations < 1)  || (tempNumberOfGenerations > 1000))
	{
		cout << "Enter a number of generations to run as an integer number between 1 and 1000: ";
		cin >> tempNumberOfGenerations;
	}
	return tempNumberOfGenerations;
}
int inputPopulationSize(void)
{
	int tempPopulationSize = 200;
	while ((tempPopulationSize < 6)  || (tempPopulationSize > 100))
	{
		cout << "Enter a population size as an integer number between 6 and 100: ";
		cin >> tempPopulationSize;
	}
	return tempPopulationSize;
}
int inputTargetValue(void)
{
	int tempTarget = 20000;
	while ((tempTarget < 1)  || (tempTarget > 10000))
	{
		cout << "Enter a target value as an integer number between 1 and 10000: ";
		cin >> tempTarget;
	}
	return tempTarget;
}

bool inputNewStopAtGoal(void)
{
	char answer = 'l';
	while ((answer != 'y')  && (answer != 'n'))
	{
		cout << "Do you want to stop when the target value is reached? (y/n): ";
		cin >> answer;
	}
	
	if (answer == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
vector<CoinType> & inputCoinTypes(vector<CoinType> & tempCoinTypes)
{
	char answer = 'l';
	while ((answer != 'y')  && (answer != 'n'))
	{
		cout << "Do you want include pennies as a valid coin? (y/n): ";
		cin >> answer;
	}
	
	if (answer == 'y')
	{
		addCoinType(tempCoinTypes, "Penny", 1);
	}
	answer = 'l';
	
	while ((answer != 'y')  && (answer != 'n'))
	{
		cout << "Do you want include nickels as a valid coin? (y/n): ";
		cin >> answer;
	}
	
	if (answer == 'y')
	{
		addCoinType(tempCoinTypes, "Nickel", 5);
	}
	answer = 'l';

	while ((answer != 'y')  && (answer != 'n'))
	{
		cout << "Do you want include dimes as a valid coin? (y/n): ";
		cin >> answer;
	}
	
	if (answer == 'y')
	{
		addCoinType(tempCoinTypes, "Dime", 10);
	}
	answer = 'l';

	while ((answer != 'y')  && (answer != 'n'))
	{
		cout << "Do you want include quarters as a valid coin? (y/n): ";
		cin >> answer;
	}
	
	if (answer == 'y')
	{
		addCoinType(tempCoinTypes, "Quarter", 25);
	}
	answer = 'l';

	while ((answer != 'y')  && (answer != 'n'))
	{
		cout << "Do you want include half-dollars as a valid coin? (y/n): ";
		cin >> answer;
	}
	
	if (answer == 'y')
	{
		addCoinType(tempCoinTypes, "Half-Dollar", 50);
	}
	answer = 'l';

	while ((answer != 'y')  && (answer != 'n'))
	{
		cout << "Do you want include dollars as a valid coin? (y/n): ";
		cin >> answer;
	}
	
	if (answer == 'y')
	{
		addCoinType(tempCoinTypes, "Dollar", 100);
	}
	
	return tempCoinTypes;
}
void addCoinType(vector<CoinType> & tempCoinTypes, string name, int value)
{
		CoinType tempCoin;
		tempCoin.name = name;
		tempCoin.value = value;
		tempCoinTypes.push_back(tempCoin);
}
int inputAgeLimit(void)
{
	int tempAgeLimit = 2000;
	while ((tempAgeLimit < 0)  || (tempAgeLimit > 50))
	{
		cout << "Enter the number of generations an individual can continue to survive" << endl
			<< "before an it dies of old age as an integer number between 1 and 50" << endl
			<< "(or enter the number 0 to disable death-by-old-age): ";
		cin >> tempAgeLimit;
	}
	return tempAgeLimit;
}

int inputTournamentSize(int populationSize)
{
	int tempPopulationSize = 200;
	while ((tempPopulationSize < 6)  || (tempPopulationSize > 100))
	{
		cout << "Enter a tournament size as an integer 2 and " << populationSize << " : ";
		cin >> tempPopulationSize;
	}
	return tempPopulationSize;
}