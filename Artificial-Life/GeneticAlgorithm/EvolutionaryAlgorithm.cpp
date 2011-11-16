#include "EvolutionaryAlgorithm.h"
EvolutionaryAlgorithm::EvolutionaryAlgorithm(vector<CoinType> & newCoinTypes, int newPopulationSize,
	int newTargetValue, int newNumberOfGenerations, double newElitismBias, int newNumberOfGenes, double newMutationRate, bool newStopAtGoal, int newAgeLimit,int newTournamentSize)
{
	setStopAtGoal(newStopAtGoal);
	
	setMutationRate(newMutationRate);
	setNumberOfGenes(newNumberOfGenes);
	setEilitismBias(newElitismBias);
	setNumberOfGenerations(newNumberOfGenerations);
	setPopulationSize(newPopulationSize);
	setTargetValue(newTargetValue);
	setCoinTypes(newCoinTypes);
	setAgeLimit(newAgeLimit);
	setTournamentSize(newTournamentSize);
	setNumberOfChildren();
}
void EvolutionaryAlgorithm::setTournamentSize(int newTournamentSize)
{
	tournamentSize = newTournamentSize;
}
void EvolutionaryAlgorithm::setMutationRate(double newMutationRate)
{
	mutationRate = newMutationRate;
}
void EvolutionaryAlgorithm::setNumberOfGenes(int newNumberOfGenes)
{
	numberOfGenes = newNumberOfGenes;
}
void EvolutionaryAlgorithm::setEilitismBias(double newElitismBias)
{
	elitismBias = newElitismBias;
}
void EvolutionaryAlgorithm::setNumberOfGenerations(int newNumberOfGenerations)
{
	numberOfGenerations = newNumberOfGenerations;
}
void EvolutionaryAlgorithm::setPopulationSize(int newPopulationSize)
{
	populationSize = newPopulationSize;
}
void EvolutionaryAlgorithm::setTargetValue(int newTargetValue)
{
	targetValue = newTargetValue;
}
void EvolutionaryAlgorithm::setNumberOfChildren()
{
	numChildren = populationSize / 3;
}
void EvolutionaryAlgorithm::setStopAtGoal(bool newStopAtGoal)
{
	stopAtGoal = newStopAtGoal;
}
void EvolutionaryAlgorithm::setCoinTypes(vector<CoinType> & newCoinTypes)
{
	typesOfCoins = newCoinTypes;
}
int EvolutionaryAlgorithm::getTournamentSize(void)
{
	return tournamentSize;
}
double EvolutionaryAlgorithm::getMutationRate(void)
{
	return mutationRate;
}
int EvolutionaryAlgorithm::getNumberOfGenes(void)
{
	return numberOfGenes;
}
double EvolutionaryAlgorithm::getEilitismBias(void)
{
	return elitismBias;
}
int EvolutionaryAlgorithm::getNumberOfGenerations(void)
{
	return numberOfGenerations;
}
int EvolutionaryAlgorithm::getPopulationSize(void)
{
	return populationSize;
}
int EvolutionaryAlgorithm::getTargetValue(void)
{
	return targetValue;
}
int EvolutionaryAlgorithm::getNumberOfChildren(void)
{
	return numChildren;
}
vector<CoinType> const & EvolutionaryAlgorithm::getCoinTypes(void)
{
	return typesOfCoins;
}
void EvolutionaryAlgorithm::initializePopulation(void)
{
	for (int counter = 0; counter < populationSize; counter++)
	{
		currentPopulation.push_back(Individual(typesOfCoins,numberOfGenes));
		currentPopulation[counter].evaluateIndividual(targetValue);
	}
}
Individual & EvolutionaryAlgorithm::selectRandomParent(void)
{
	return currentPopulation[rand() % populationSize];
}
void EvolutionaryAlgorithm::selectSurvivors(void)
{
	elitism();
	tournament.clear();
	int needeSurviorsLeft = populationSize - survivors.size();
	for (int tour = 0; tour < needeSurviorsLeft; tour++)
	{
		for(int participant = 0; participant < tournamentSize; participant++)
		{
			//add an individual that is not already surviving and is not too old to live on to the tournament;
			int selectedIndividual = rand() % currentPopulation.size();
			while (currentPopulation[selectedIndividual].getAlreadySurvived() || currentPopulation[selectedIndividual].getGoingToDie())
			{
				selectedIndividual = rand() % currentPopulation.size();
			}
			tournament.push_back(&currentPopulation[selectedIndividual]);
		}
		sort(tournament.begin(), tournament.end(), Individual::individualPointerLessThan);
		survivors.push_back(tournament[0]->incrementAge());
		tournament[0]->setAsSurvivor();
		tournament.clear();
	}
}
void EvolutionaryAlgorithm::elitism(void)
{
	
	
	int counter = 0;
	while (counter < (elitismBias*populationSize))
	{
		if (currentPopulation[counter].getGoingToDie() == false)
		{
			survivors.push_back(currentPopulation[counter].incrementAge());
			currentPopulation[counter].setAsSurvivor();
		}
			counter++;
	}
}
int EvolutionaryAlgorithm::generateAverage(void)
{
	int average = 0;

	for (int count = 0; count < currentPopulation.size(); count++)
	{
		average += currentPopulation[count].getTotalValue();
	}
	return average / currentPopulation.size();
}
void EvolutionaryAlgorithm::print(int generation, int numDeaths)
{
	cout << "\nGeneration " << generation << ": Avg=" << generateAverage()
		<< ", Number of old-age deaths: " << numDeaths << ", Best: T=" << currentPopulation[0].getTotalValue() << " cents";
	for (int count = 0; count < typesOfCoins.size(); count++)
	{
		cout << ", " <<typesOfCoins[count].name << "=" << currentPopulation[0].numberOfGenesWithValue(typesOfCoins[count].value);
	}
}
void EvolutionaryAlgorithm::setAgeLimit(int newAgeLimit)
{
	ageLimit = newAgeLimit;
}
void EvolutionaryAlgorithm::setDeaths(void)
{
	if (ageLimit > 0)
	{
		for (int counter = 0; counter < currentPopulation.size(); counter++)
		{
			if (currentPopulation[counter].getAge() >= ageLimit)
			{
				currentPopulation[counter].isGoingToDie();
			}
	
		}
	}
}
int EvolutionaryAlgorithm::getNumberOfDeaths(void)
{
	int numDeaths = 0;
	if (ageLimit > 0)
	{
		for (int counter = 0; counter < currentPopulation.size(); counter++)
		{
			if (currentPopulation[counter].getGoingToDie())
			{
				numDeaths++;
			}
		}
	}
	return numDeaths;
}
void EvolutionaryAlgorithm::run()
{
	initializePopulation();
	bool goal = false;
	for (int generation = 0; (generation < numberOfGenerations) && !goal; generation++)
	{
		setDeaths();
		int newDeaths = getNumberOfDeaths();
		int newChildren = numChildren + newDeaths;
		for (int childNumber = 0; childNumber < newChildren; childNumber++)
		{
			Individual child(selectRandomParent(), selectRandomParent(), numberOfGenes);

			if ((rand() % 1000) < (mutationRate * 1000))
			{
				child.mutateIndividual(typesOfCoins);
			}
			child.evaluateIndividual(targetValue);
			currentPopulation.push_back(child);
		}

		sort(currentPopulation.begin(),  currentPopulation.end());
		selectSurvivors();
		currentPopulation.clear();
		currentPopulation = survivors;
		survivors.clear();
		sort(currentPopulation.begin(),  currentPopulation.end());
		print(generation, newDeaths);
		if (generation % 10 == 0)
		{
			cout << endl;
			system("PAUSE");
			cout << endl;
		}
		if(currentPopulation[0].getFitnessLevel() == 0)
		{
			goal = true;
			cout << endl << "GOAL REACHED\n";
			system("PAUSE");
			cout << endl;
			return ;
		}
	}
}