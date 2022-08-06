/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: monkey class source file.
*******************************************************************************/
#include "monkey.hpp"
#include <string>
/*******************************************************************************
** Function Name: Default Constructor.
** Description: Assigns certain attributes to their animal-specific level.
*******************************************************************************/
monkey::monkey() : Animal() {
	cost = 12000;
	numBabies = 1;
	baseFoodCost = 100;
	payoff = cost * .03;
  sick=2400;
	type = "monkey";
}
/*******************************************************************************
** Function Name: Constructor with param.
** Description: Sets the age to the param.
*******************************************************************************/
monkey::monkey(int a) : Animal() {
	cost = 12000;
	numBabies = 1;
  sick=2400;
	baseFoodCost = 100;
	payoff = cost * .03;
	type = "monkey";
	age = a;
}
