#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include <vector>
using namespace std;
#include <stdlib.h>
#include <math.h>
using std::abs;
using std::rand;

#include "Coin.h"

class Individual
{
	

public:
	static bool individualPointerLessThan(Individual *a, Individual *b);
	Individual(const vector<CoinType> & geneTypes, int numGenes);
	Individual(const Individual & source, int numGenes);
	Individual(Individual & parent1, Individual & parent2, int numGenes);
	~Individual(void);
	void mutateIndividual(const vector<CoinType> & geneTypes);
	void evaluateIndividual(int targetValue);
	void setAsSurvivor(void);
	void isGoingToDie(void);
	int getFitnessLevel(void);
	int getTotalValue(void);
	int getAge(void);
	bool getGoingToDie(void);
	Individual & incrementAge(void);
	int numberOfGenesWithValue(int value);
	bool getAlreadySurvived(void);
	bool operator<(const Individual & rightIndividual);

private:
	int totalValue;
	int fitnessLevel;
	bool isSurvivor;
	int age;
	bool goingToDie;
	vector<CoinType const *> genome;
};
#endif