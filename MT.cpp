#include "MT.h"
#include <iostream>

// Constructor
MT::MT()
{
	std::random_device rd;		//Will be used to obtain a seed for the random number engine
	std::seed_seq seed{ rd(), rd(), rd(), rd() }; // Set multiple random numbers for the seed
	std::mt19937 gen(seed);		//Standard mersenne_twister_engine seeded with multiples rd()
	m_MTGen = gen;
}

// Returns an instance of the MT
MT& MT::getInstance()
{
	static std::unique_ptr<MT> instance(new MT());
	return *instance;
}

// Returns a random number from a standard uniform distribution
double MT::rand_unif(std::mt19937& generator)
{
	std::uniform_real_distribution<> unifDistrib(0.0, 1.0);
	return unifDistrib(generator);
}

// Returns a random number from a standard normal distribution
double MT::rand_norm(std::mt19937& generator)
{
	std::normal_distribution<> normDistrib(0.0, 1.0);
	return normDistrib(generator);
}

// Returns the generator of the instance
std::mt19937 MT::getGen() { return m_MTGen; }
