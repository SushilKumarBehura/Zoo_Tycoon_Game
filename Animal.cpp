/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: Animal class source file.
*******************************************************************************/
#include "Animal.hpp"

/*******************************************************************************
** Function Name: Default Constructor.
** Description: Assigns certain attributes to their base level and sets age
** to be 104weeks(2 years) old.
*******************************************************************************/
Animal::Animal() {
	age = 104;
	cost = 0;
  sick=0;
	numBabies = 1;
	baseFoodCost = 25;
	payoff = 0;
	type = "Generic Animal";
}
/*******************************************************************************
** Function Name: Constructor with params.
** Description: Sets the animal's age.
*******************************************************************************/
Animal::Animal(int a) {
	age = a;
}
/*******************************************************************************
** Function Name: Default Destructor.
** Description: Destructor.
*******************************************************************************/
Animal::~Animal() {
}
/*******************************************************************************
** Function Name: Get Type
** Description: Returns the type of animal it is in the form of a string.
*******************************************************************************/
std::string Animal::getType() {
	return type;
}
/*******************************************************************************
** Function Name: Get Age
** Description: Returns the age, in weeks.
*******************************************************************************/
int Animal::getAge() {
	return age;
}
int Animal::getSick(){
  return sick;
}
/*******************************************************************************
** Function Name: Get Cost
** Description: Returns the cost of the animal.
*******************************************************************************/
int Animal::getCost() {
	return cost;
}
/*******************************************************************************
** Function Name: Get Base Food Cost.
** Description: Returns the base food cost.
*******************************************************************************/
int Animal::getBaseFoodCost() {
	return baseFoodCost;
}
/*******************************************************************************
** Function Name: Get Payoff.
** Description: Returns the payoff of the animal (How much money it makes).
*******************************************************************************/
int Animal::getPayoff() {
	return payoff;
}
/*******************************************************************************
** Function Name: Get Num Babies.
** Description: Returns the number of babies the animal can have.
*******************************************************************************/
int Animal::getNumBabies() {
	return numBabies;
}
/*******************************************************************************
** Function Name: Age One Week.
** Description: Makes the animal one week older.
*******************************************************************************/
void Animal::ageOneWeek() {
	age++;
}
