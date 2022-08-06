/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: Animal class header.
*******************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
	int age, cost, numBabies, baseFoodCost, payoff,sick;
	std::string type;

public:
	Animal();	// Default constructor.
	Animal(int); // Constructor with age only.
	~Animal();   // Default destructor.
	std::string getType();
	int getAge();
  int getSick();
	int getCost();
	int getBaseFoodCost();
	int getPayoff();
	int getNumBabies();
	void ageOneWeek();
};

#endif