#include <vector>
using namespace std;
#include <stdlib.h>
#include <math.h>
using std::abs;
using std::rand;
#include "Individual.h"
#include "Coin.h"

bool Individual::individualPointerLessThan( Individual *a,  Individual *b)
{
	return a->getFitnessLevel() < b->getFitnessLevel();
}
Individual::Individual(const vector<CoinType> & geneTypes, int numGenes)
{
	for (int counter = 0; counter < numGenes; counter++)
	{
		genome.push_back(&geneTypes[rand() % geneTypes.size()]);
	}
	fitnessLevel = 0;
	totalValue = 0;
	age = 0;
	isSurvivor = false;
	goingToDie = false;
}
Individual::Individual(const Individual & source, int numGenes)
{
	for (int counter = 0; counter < numGenes; counter++)
	{
		genome.push_back(source.genome[counter]);
	}
	age = source.age;
	fitnessLevel = source.fitnessLevel;
	totalValue = source.totalValue;
	isSurvivor = false;
	goingToDie = false;
}
Individual::Individual(Individual & parent1, Individual & parent2, int numGenes)
{
	int splitPoint = numGenes / 2;
	int counter;

	for (counter = 0; counter < splitPoint; counter++)
	{
		genome.push_back(parent1.genome[counter]);
	}

	for (counter = splitPoint; counter < numGenes; counter++)
	{
		genome.push_back(parent2.genome[counter]);
	}
	fitnessLevel = 0;
	totalValue = 0;
	age = 0;
	isSurvivor = false;
	goingToDie = false;
}
Individual::~Individual(void)
{
}
void Individual::mutateIndividual(const vector<CoinType> & geneTypes)
{
	genome[rand() % genome.size()] = &geneTypes[rand() % geneTypes.size()];
}
void Individual::evaluateIndividual(int targetValue)
{
	totalValue = 0;
	for (int counter = 0; counter < genome.size();counter++)
	{
		totalValue += genome[counter]->value;
	}

	fitnessLevel = abs(targetValue - totalValue);
}
int Individual::getFitnessLevel(void)
{
	return fitnessLevel;
}
int Individual::getTotalValue(void)
{
	return totalValue;
}
int Individual::numberOfGenesWithValue(int value)
{
	int genesWithValue = 0;
	for (int geneNumber = 0; geneNumber < genome.size(); geneNumber++)
	{
		if (genome[geneNumber]->value == value)
		{
			genesWithValue++;
		}
	}
	return genesWithValue;
}
bool Individual::operator<(const Individual & rightIndividual)
{
	return this->fitnessLevel < rightIndividual.fitnessLevel;
}
void Individual::setAsSurvivor(void)
{
	isSurvivor = true;
}
bool Individual::getAlreadySurvived(void)
{
	return isSurvivor;
}
int Individual::getAge(void)
{
	return age;
}
Individual & Individual::incrementAge(void)
{
	age++;
	return *this;
}
bool Individual::getGoingToDie(void)
{
	return goingToDie;
}
void Individual::isGoingToDie(void)
{
	goingToDie = true;
}