/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: Zoo class header.
*******************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "meerkat.hpp"
#include "monkey.hpp"
#include "seaotter.hpp"

class Zoo {
private:
	Animal **monkeys, **seaotters, **meerkats;
	int monkeyArraySize, seaotterArraySize, meerkatArraySize, bank,
		attendanceBonus;

public:
	Zoo();
	~Zoo();
	void addAnimal(Animal *);
	void addmonkey(Animal *);
	void addseaotter(Animal *);
	void addmeerkat(Animal *);
	void deleteAnimalArrays();
	void printAnimals();
	bool isArrayFull(Animal **, int);
	void resizeArray(Animal **&, int &);
	void playGame();
	int getBankAccount();
	void makePayment(int);
	void getPaid(int);
	void animalPurchaseMenu();
	void monkeyPurchaseMenu();
	void seaotterPurchaseMenu();
	void meerkatPurchaseMenu();
	void ageAllAnimals();
	int calculateFeedingCosts();
	void randomEvent();
	void sickAnimal();
	void boomInAttendance();
	void babyBorn();
	void monkeyDies();
	void seaotterDies();
	void meerkatDies();
	void buyAdultAnimal();
	int calculatePayoff();
};

#endif
