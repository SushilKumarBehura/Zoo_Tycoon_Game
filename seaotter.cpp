/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: seaotter class source file.
*******************************************************************************/
#include "seaotter.hpp"
/*******************************************************************************
** Function Name: Default Constructor.
** Description: Assigns certain attributes to their animal-specific level.
*******************************************************************************/
seaotter::seaotter() : Animal() {
	cost = 4000;
	numBabies = 1;
	baseFoodCost = 50;
	payoff = cost * .05;
  sick=800;
	type = "seaotter";
}
/*******************************************************************************
** Function Name: Constructor with param.
** Description: Sets the age to the param.
*******************************************************************************/
seaotter::seaotter(int a) : Animal() {
	cost = 4000;
	numBabies = 1;
	baseFoodCost = 50;
	payoff = cost * .05;
  sick=800;
	type = "seaotter";
	age = a;
}