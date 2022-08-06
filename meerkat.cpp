/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: Meerkat class source file.
*******************************************************************************/
#include "meerkat.hpp"

meerkat::meerkat() : Animal() {
	cost = 500;
	numBabies = 3;
	baseFoodCost = 25;
	payoff = cost * .05;
  sick=100;
	type = "meerkat";
}
/*******************************************************************************
** Function Name: Constructor with param.
** Description: Sets the age to the param.
*******************************************************************************/
meerkat::meerkat(int a) : Animal() {
	cost = 500;
	numBabies = 3;
	baseFoodCost = 25;
	payoff = cost * .05;
  sick=100;
	type = "meerkat";
	age = a;
}