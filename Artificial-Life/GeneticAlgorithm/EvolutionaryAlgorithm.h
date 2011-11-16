#ifndef EVOLUTIONARYALGORITHM_H_
#define EVOLUTIONARYALGORITHM_H_

#include <vector>
#include <string>
using namespace std;
#include <algorithm>
#include <iostream>
using std::cout;
using std::sort;
#include "Coin.h"
#include "Individual.h"

class EvolutionaryAlgorithm
{
public:
	EvolutionaryAlgorithm(vector<CoinType> & newCoinTypes, int newPopulationSize,
		int newTargetValue, int newNumberOfGenerations, double newElitismBias, int newNumberOfGenes, double newMutationRate, bool newStopAtGoal, int newAgeLimit, int newTournamentSize);

	void setTournamentSize(int newTournamentSize);
	void setMutationRate(double newMutationRate);
	void setNumberOfGenes(int newNumberOfGenes);
	void setEilitismBias(double newElitismBias);
	void setNumberOfGenerations(int newNumberOfGenerations);
	void setPopulationSize(int newPopulationSize);
	void setTargetValue(int newTargetValue);
	void setNumberOfChildren();
	void setAgeLimit(int newAgeLimit);
	void setStopAtGoal(bool newStopAtGoal);
	void setCoinTypes(vector<CoinType> & newCoinTypes);
	int getTournamentSize(void);
	double getMutationRate(void);
	int getNumberOfGenes(void);
	double getEilitismBias(void);
	int getNumberOfGenerations(void);
	int getPopulationSize(void);
	int getTargetValue(void);
	int getNumberOfChildren(void);
	vector<CoinType> const & getCoinTypes(void);
	void initializePopulation(void);
	Individual & selectRandomParent(void);
	void selectSurvivors(void);
	void setDeaths(void);
	int getNumberOfDeaths(void);
	void elitism(void);
	int generateAverage(void);
	void print(int generation, int numDeaths);
	void run();

	

private:
	bool stopAtGoal;
	int tournamentSize;
	double mutationRate;
	int numberOfGenes;
	double elitismBias;
	int numberOfGenerations;
	int populationSize;
	int targetValue;
	int numChildren;
	int ageLimit;
	vector<CoinType> typesOfCoins;
	vector<Individual> currentPopulation;
	vector<Individual> survivors;
	vector<Individual*> tournament;


};
#endif