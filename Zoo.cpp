/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: Zoo class source file.
*******************************************************************************/
#include "Zoo.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
// Prototypes.
int validateBinaryChoice();
int validateTrinaryChoice();
/*******************************************************************************
** Function Name: Default Constructor.
** Description: Sets dynamic arrays for each animal to their base size of 10,
** filling each element with NULL, since they're empty. Gives the player
** $50k to start with as well.
*******************************************************************************/
Zoo::Zoo() {
	monkeys = new Animal *[100];
	seaotters = new Animal *[100];
	meerkats = new Animal *[100];
	monkeyArraySize = seaotterArraySize = meerkatArraySize = 100;
	bank = 100000;
	attendanceBonus = 0;

	for (int i = 0; i < 100; i++) {
		monkeys[i] = NULL;
		seaotters[i] = NULL;
		meerkats[i] = NULL;
	}
}
/*******************************************************************************
** Function Name: Default Destructor.
** Description: Default Destructor.
*******************************************************************************/
Zoo::~Zoo() {
}
/*******************************************************************************
** Function Name: Add Animal.
** Description: Adds an animal to its dynamic array of animals. It will check
** the animal's type to see what kind of animal it is and which array to add it
** to. Then it calls that specific function for the animal adding.
*******************************************************************************/
void Zoo::addAnimal(Animal *a) {
	if (a->getType() == "monkey") {
		addmonkey(a);
	} else if (a->getType() == "seaotter") {
		addseaotter(a);
	} else if (a->getType() == "meerkat") {
		addmeerkat(a);
	}
}
/*******************************************************************************
** Function Name: Add monkey.
** Description: Adds a monkey to the dynamic monkey array. It checks each
*element
** to see if it is empty, then adds a new object to the first available empty
** spot. Before it does this, it will check if the array is full. If it is, it
** will resize the array and then continue to add the animal pointer. If it is
** not full, it will just add the pointer and call it good.
*******************************************************************************/
void Zoo::addmonkey(Animal *a) {
	if (isArrayFull(monkeys, monkeyArraySize)) {
		std::cout << "Can't purchase more than 100 monkeys" << std::endl;
	} else {
		for (int i = 0; i < monkeyArraySize; i++) {
			if (monkeys[i] == NULL) {
				monkeys[i] = a;
				break;
			}
		}
	}
}
/*******************************************************************************
** Function Name: Add seaotter.
** Description: Adds a monkey to the dynamic monkey array. It checks each
*element
** to see if it is empty, then adds a new object to the first available empty
** spot. Before it does this, it will check if the array is full. If it is, it
** will resize the array and then continue to add the animal pointer. If it is
** not full, it will just add the pointer and call it good.
*******************************************************************************/
void Zoo::addseaotter(Animal *a) {
	if (isArrayFull(seaotters, seaotterArraySize)) {
		std::cout << "Can't purchase more than 100 seaotters" << std::endl;
	} else {
		for (int i = 0; i < seaotterArraySize; i++) {
			if (seaotters[i] == NULL) {
				seaotters[i] = a;
				break;
			}
		}
	}
}
/*******************************************************************************
** Function Name: Add meerkat.
** Description: Adds a monkey to the dynamic monkey array. It checks each
*element
** to see if it is empty, then adds a new object to the first available empty
** spot. Before it does this, it will check if the array is full. If it is, it
** will resize the array and then continue to add the animal pointer. If it is
** not full, it will just add the pointer and call it good.
*******************************************************************************/
void Zoo::addmeerkat(Animal *a) {
	if (isArrayFull(meerkats, meerkatArraySize)) {
		std::cout << "Can't purchase more than 100 meerkats" << std::endl;
	} else {
		for (int i = 0; i < meerkatArraySize; i++) {
			if (meerkats[i] == NULL) {
				meerkats[i] = a;
				break;
			}
		}
	}
}
/*******************************************************************************
** Function Name: Delete Animal Arrays
** Description: Deletes the dynamically allocated arrays that hold animals in
** order to prevent memory leak. This is for the end of the program. It deletes
** each object pointer in each array position that is not NULL, then deletes the
** array pointer itself.
*******************************************************************************/
void Zoo::deleteAnimalArrays() {
	int i = 0;

	while (monkeys[i] != NULL) {
		delete monkeys[i];
		i++;
	}

	i = 0;
	while (seaotters[i] != NULL) {
		delete seaotters[i];
		i++;
	}

	i = 0;
	while (meerkats[i] != NULL) {
		delete meerkats[i];
		i++;
	}

	delete[] monkeys;
	delete[] seaotters;
	delete[] meerkats;
}
/*******************************************************************************
** Function Name: Print Animals
** Description: Prints out the details of each animal in this zoo's arrays of
** animals. It prints them by animal type.
*******************************************************************************/
void Zoo::printAnimals() {
	std::cout << "Animals in the zoo: " << std::endl;
	int i = 0;
	int nummonkeys = 0;
	int numseaotters = 0;
	int nummeerkats = 0;

	while (monkeys[i] != NULL) {
		nummonkeys++;
		i++;
	}

	i = 0;
	while (seaotters[i] != NULL) {
		numseaotters++;
		i++;
	}

	i = 0;
	while (meerkats[i] != NULL) {
		nummeerkats++;
		i++;
	}

	std::cout << "monkeys: " << nummonkeys << std::endl;
	std::cout << "seaotters: " << numseaotters << std::endl;
	std::cout << "meerkats: " << nummeerkats << std::endl;
}
/*******************************************************************************
** Function Name: Resize Array
** Description: 'Resizes' the dynamic animal array. It actually just creates a
** new dynamic array twice the size of the current one, then copies the contents
** of the current array into the new, bigger one. Then the old one is deleted
** and the member variable keeping track of that array's size is updated.
** source:
*https://stackoverflow.com/questions/8056746/copying-from-one-dynamically-allocated-array-to-another-c
** This takes a pointer to a pointer Animal array passed by value to change it.
*******************************************************************************/
void Zoo::resizeArray(Animal **&a, int &size) {
	Animal **newArray = new Animal *[size * 2];

	// Set each element in the newly created array to NULL, so they're
	// not going to cause a problem in the future.
	for (int i = 0; i < size * 2; i++) {
		newArray[i] = NULL;
	}

	// Copy the old array contents into the new.
	for (int i = 0; i < size; i++) {
		newArray[i] = a[i];
	}

	delete[] a; // Sever the connection to the old array.

	a = newArray; // set our

	size = size * 2; // Update the size of this specific array by value.
}
/*******************************************************************************
** Function Name: Is Array Full
** Description: Checks if the array is full. This will be used with the add
** animal function to check if we need to 'resize' the array to fit the new
** animal object. Goes through each element in the array and checks if there
** is something there. If it finds an empty index, it will return false. If it
** reaches the end without finding an empty index, it returns true. It takes a
** pointer to a pointer Animal array (such as monkey array or seaotter array).
*******************************************************************************/
bool Zoo::isArrayFull(Animal **a, int size) {
	for (int i = 0; i < size; i++) {
		if (!a[i]) // If the index at the address is empty..
		{
			return false;
		}
	}

	return true;
}
/*******************************************************************************
** Function Name: Get Bank Account
** Description: Returns the amount of money the player has left in the bank.
*******************************************************************************/
int Zoo::getBankAccount() {
	return bank;
}
/*******************************************************************************
** Function Name: Make Payment
** Description: Subtracts money from the bank account based on the argument
*passed.
*******************************************************************************/
void Zoo::makePayment(int m) {
	bank = bank - m;
	;
}
/*******************************************************************************
** Function Name: Get Paid
** Description: Adds money to the bank account based on the argument passed.
*******************************************************************************/
void Zoo::getPaid(int m) {
	bank = bank + m;
}
/*******************************************************************************
** Function Name: monkey Purchase Menu
** Description: Menu for handling the purchasing of monkeys at the start.
*******************************************************************************/
void Zoo::monkeyPurchaseMenu() {
	int choice;

	std::cout << "Monkeys are $12,000. You currently have $" << getBankAccount()
			  << " in your account." << std::endl;
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1.Buy no monkeys" << std::endl;
	std::cout << "2.Buy one monkey" << std::endl;

	choice = validateBinaryChoice();

	if (choice == 1) {
		std::cout << "You didn't buy any monkey. You have $" << getBankAccount()
				  << " remaining." << std::endl;
	} else if (choice == 2) {
		makePayment(12000);
		std::cout << "You bought one monkey for $12,000. You have $"
				  << getBankAccount() << " remaining." << std::endl;
		addAnimal(new monkey(104));
	}
	std::cout << "-----------------" << std::endl;
}
/*******************************************************************************
** Function Name: seaotter Purchase Menu
** Description: Menu for handling the purchasing of seaotters at the start.
*******************************************************************************/
void Zoo::seaotterPurchaseMenu() {
	int choice;

	std::cout << "Seaotters are $4,000. You currently have $"
			  << getBankAccount() << " in your account." << std::endl;
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1.Buy no seaotters" << std::endl;
	std::cout << "2.Buy one seaotter" << std::endl;

	choice = validateBinaryChoice();

	if (choice == 1) {
		std::cout << "You didn't buy any seaotter. You have $"
				  << getBankAccount() << " remaining." << std::endl;
	} else if (choice == 2) {
		makePayment(4000);
		std::cout << "You bought one seaotters for $4,000. You have $"
				  << getBankAccount() << " remaining." << std::endl;
		addAnimal(new seaotter(104));
	}
	std::cout << "-----------------" << std::endl;
}
/*******************************************************************************
** Function Name: meerkat Purchase Menu
** Description: Menu for handling the purchasing of meerkats at the start.
*******************************************************************************/
void Zoo::meerkatPurchaseMenu() {
	int choice;

	std::cout << "Meerkats are $500. You currently have $" << getBankAccount()
			  << " in your account." << std::endl;
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1.Buy no meerkats" << std::endl;
	std::cout << "2.Buy one meerkats" << std::endl;

	choice = validateBinaryChoice();

	if (choice == 1) {
		std::cout << "You didn't buy any meerkats. You have $"
				  << getBankAccount() << " remaining." << std::endl;
	} else if (choice == 2) {
		makePayment(500);
		std::cout << "You bought one meerkats for $500. You have $"
				  << getBankAccount() << " remaining." << std::endl;
		addAnimal(new meerkat(104));
	}
}
/*******************************************************************************
** Function Name: Animal Purchase Menu
** Description: Menu for handling the purchasing of animals at the start.
*******************************************************************************/
void Zoo::animalPurchaseMenu() {
	std::cout << "You need to buy at least one animal out of three different species." << std::endl;
	monkeyPurchaseMenu();
	seaotterPurchaseMenu();
	meerkatPurchaseMenu();
}
/*******************************************************************************
** Function Name: Age all Animals
** Description: Increases the age of all animals in the zoo by 1 week.
*******************************************************************************/
void Zoo::ageAllAnimals() {
	int i = 0;

	while (monkeys[i] != NULL) {
		monkeys[i]->ageOneWeek();
		i++;
	}

	i = 0;
	while (seaotters[i] != NULL) {
		seaotters[i]->ageOneWeek();
		i++;
	}

	i = 0;
	while (meerkats[i] != NULL) {
		meerkats[i]->ageOneWeek();
		i++;
	}
}
/*******************************************************************************
** Function Name: Calculate Feeding Costs
** Description: Calculates the total cost of feeding all the animals.
*******************************************************************************/
int Zoo::calculateFeedingCosts() {
	int i = 0;
	int totalCost = 0;

	while (monkeys[i] != NULL) {
		totalCost += monkeys[i]->getBaseFoodCost();
		i++;
	}

	i = 0;
	while (seaotters[i] != NULL) {
		totalCost += seaotters[i]->getBaseFoodCost();
		i++;
	}

	i = 0;
	while (meerkats[i] != NULL) {
		totalCost += meerkats[i]->getBaseFoodCost();
		i++;
	}

	return totalCost;
}
/*******************************************************************************
** Function Name: Calculate Payoff
** Description: Calculates the total payoff all the animals for the week.
*******************************************************************************/
int Zoo::calculatePayoff() {
	int i = 0;
	int totalPayoff = 0;

	while (monkeys[i] != NULL) {
		totalPayoff += monkeys[i]->getPayoff();
    if(monkeys[i]->getAge()<7){
      totalPayoff += monkeys[i]->getPayoff();
    }
		i++;
	}

	i = 0;
	while (seaotters[i] != NULL) {
		totalPayoff += seaotters[i]->getPayoff();
    if(seaotters[i]->getAge()<7){
      totalPayoff += seaotters[i]->getPayoff();
    }
		i++;
	}

	i = 0;
	while (meerkats[i] != NULL) {
		totalPayoff += meerkats[i]->getPayoff();
    if(meerkats[i]->getAge()<7){
      totalPayoff += meerkats[i]->getPayoff();
    }
		i++;
	}

	return totalPayoff;
}
/*******************************************************************************
** Function Name: monkey Dies
** Description: The last monkey in the monkey array dies.
*******************************************************************************/
void Zoo::monkeyDies() {
	int lastIndex;
	int i = 0;

	while (monkeys[i] != NULL) {
		lastIndex = i;
		i++;
	}
  if(monkeys[i-1]->getAge()<7){
    std::cout<<"Baby monkey got sick."<<std::endl;
    if(bank>=(monkeys[i-1]->getSick()*2)){
      makePayment(4800);
      std::cout<<"Baby monkey has been cured and it took $4800 to cure the disease."<<std::endl;
      std::cout<<"Remaining balance is $"<<getBankAccount()<<std::endl;
    }
    else{
      delete monkeys[i - 1];
	    monkeys[i - 1] = NULL;
      std::cout << "Baby monkey has died." << std::endl;
    }
  }
  else{
    std::cout<<"Monkey got sick."<<std::endl;
    if(bank>=(monkeys[i-1]->getSick())){
      makePayment(2400);
      std::cout<<"Monkey has been cured and it took $2400 to cure the disease."<<std::endl;
      std::cout<<"Remaining balance is $"<<getBankAccount()<<std::endl;
    }
    else{
      delete monkeys[i - 1];
	    monkeys[i - 1] = NULL;
      std::cout << "A monkey has died." << std::endl;
    }
  }
	
}
/*******************************************************************************
** Function Name: seaotter Dies
** Description: The last seaotter in the seaotter array dies.
*******************************************************************************/
void Zoo::seaotterDies() {
	int lastIndex;
	int i = 0;

	while (seaotters[i] != NULL) {
		lastIndex = i;
		i++;
	}
  if(seaotters[i-1]->getAge()<7){
    std::cout<<"Baby seaotter got sick."<<std::endl;
    if(bank>=(seaotters[i-1]->getSick()*2)){
      makePayment(1600);
      std::cout<<"Baby seaotter has been cured and it took $1600 to cure the disease."<<std::endl;
      std::cout<<"Remaining balance is $"<<getBankAccount()<<std::endl;
    }
    else{
      delete seaotters[i - 1];
	    seaotters[i - 1] = NULL;
      std::cout << "Baby seaotter has died." << std::endl;
    }
  }
  else{
    std::cout<<"Seaotter got sick."<<std::endl;
    if(bank>=(seaotters[i-1]->getSick())){
      makePayment(800);
      std::cout<<"Seaotter has been cured and it took $800 to cure the disease."<<std::endl;
      std::cout<<"Remaining balance is $"<<getBankAccount()<<std::endl;
    }
    else{
      delete seaotters[i - 1];
	    seaotters[i - 1] = NULL;
      std::cout << "A seaotter has died." << std::endl;
    }
  }
}
/*******************************************************************************
** Function Name: meerkat Dies
** Description: The last meerkat in the meerkat array dies.
*******************************************************************************/
void Zoo::meerkatDies() {
	int lastIndex;
	int i = 0;

	while (meerkats[i] != NULL) {
		lastIndex = i;
		i++;
	}
  if(meerkats[i-1]->getAge()<7){
    std::cout<<"Baby meerkat got sick."<<std::endl;
    if(bank>=(meerkats[i-1]->getSick()*2)){
      makePayment(200);
      std::cout<<"Baby meerkat has been cured and it took $200 to cure the disease."<<std::endl;
      std::cout<<"Remaining balance is $"<<getBankAccount()<<std::endl;
    }
    else{
      delete meerkats[i - 1];
	    meerkats[i - 1] = NULL;
      std::cout << "Baby meerkat has died." << std::endl;
    }
  }
  else{
    std::cout<<"meerkat got sick."<<std::endl;
    if(bank>=(meerkats[i-1]->getSick())){
      makePayment(100);
      std::cout<<"meerkat has been cured and it took $100 to cure the disease."<<std::endl;
      std::cout<<"Remaining balance is $"<<getBankAccount()<<std::endl;
    }
    else{
      delete meerkats[i - 1];
	    meerkats[i - 1] = NULL;
      std::cout << "A meerkat has died." << std::endl;
    }
  }
}
/*******************************************************************************
** Function Name: Random Event
** Description: Rolls a random event.
*******************************************************************************/
void Zoo::randomEvent() {
	int roll = (rand() % 4 + 1);
	std::cout << "Random event: ";

	switch (roll) {
	case 1:
		std::cout << "Bad News!!!" << std::endl;
		sickAnimal();
		break;
	case 2:
		std::cout << "A boom in attendance!!!" << std::endl;
		boomInAttendance();
		break;
	case 3:
		std::cout << "Good News!!!" << std::endl;
		babyBorn();
		break;
	case 4:
		std::cout << "Nothing happened this week." << std::endl;
		break;
	default:
		std::cout << "error in random roll." << std::endl;
		break;
	}
}
/*******************************************************************************
** Function Name: Sick Animal
** Description: A random animal gets sick and dies.
*******************************************************************************/
void Zoo::sickAnimal() {
	int roll = (rand() % 3 + 1);

	switch (roll) {
	case 1:
		if (monkeys[0] == NULL) // If no monkeys in the array, give message.
		{
			std::cout << "A monkey sickness has spread, but there are no monkeys left."<< std::endl;
			break;
		}
    else // Otherwise, kill the monkey.
		{
			monkeyDies();
		}
		break;
	case 2:
		if (seaotters[0] == NULL) // If no seaotters in the array, give message.
		{
			std::cout << "A seaotter sickness has spread, but there are no seaotters left."<< std::endl;
			break;
		} else // Otherwise, kill the seaotter.
		{
			seaotterDies();
		}
		break;
	case 3:
		if (meerkats[0] == NULL) // If no meerkats in the array, give message.
		{
			std::cout << "A meerkat sickness has spread, but there are no meerkats left."<< std::endl;
			break;
		} else // Otherwise, kill the meerkat.
		{
			meerkatDies();
		}
		break;
	default:
		std::cout << "error in sick animal random roll." << std::endl;
		break;
	}
}
/*******************************************************************************
** Function Name: Boom in Attendance
** Description: More people come to the zoo, driving up ticket sales.
*******************************************************************************/
void Zoo::boomInAttendance() {
	// For each monkey, get 250-500 extra dollars.
	int i = 0;
	int totalmonkeys = 0;
	int bonus = 0;

	// Counting monkeys.
	while (monkeys[i] != NULL) {
		i++;
		totalmonkeys = i;
	}

	if (totalmonkeys != 0) // If you have at least one monkey, get bonus.
	{
		int roll = (rand() % 701) + 500;

		bonus = (totalmonkeys)*roll;
		std::cout << "There was a boom in zoo attendance this week! Your "
				  << (totalmonkeys) << " monkey(s) made you an extra $" << bonus
				  << "!" << std::endl;

		getPaid(bonus);			 // Add the bonus money to bank.
		attendanceBonus = bonus; // Set bonus to be used in main game loop for
								 // profit description.
	} else						 // Otherwise, get the below message.
	{
		std::cout << "You have no monkeys..." << std::endl;
	}
}
/*******************************************************************************
** Function Name: Baby Born
** Description: A random animal has a baby.
*******************************************************************************/
void Zoo::babyBorn() {
	int roll = (rand() % 3 + 1);
	int i = 0;
	int count = 0;
	bool born = false; // For keeping track if babies were born successfully.

	switch (roll) {
	case 1:
		while (monkeys[i] !=
			   NULL) // Check if any monkeys are at least 104 weeks (2years) old.
		{
			if (monkeys[i]->getAge() >= 104) // If they are, a baby is born.
			{
				count++;
			}
			i++;
		}
		if (count >= 2) {
			std::cout << "A baby monkey was born." << std::endl;
			addAnimal(new monkey(0)); // Add one baby monkey, aged 0.
			born = true;
			break;
		}
		// Otherwise, tell the user no babies can be born.
		std::cout << "There are no monkeys able to have children." << std::endl;
		break;
	case 2:
		while (seaotters[i] != NULL) {
			if (seaotters[i]->getAge() >= 104) {
				count++;
			}
			i++;
		}
		if (count >= 2) {
			std::cout << "A baby seaotter was born." << std::endl;
			addAnimal(new seaotter(0)); // Add a baby seaotter, aged 0.
			born = true;
			break;
		}
		// If no seaotters were born, give below message.
		std::cout << "There are no seaotters able to have children."
				  << std::endl;
		break;
	case 3:
		while (meerkats[i] != NULL) {
			if (meerkats[i]->getAge() >= 2) {
				count++;
			}
			i++;
		}
		if (count >= 2) {
			std::cout << "Three baby meerkats were born." << std::endl;
			for (int i = 0; i < 3; i++) {
				addAnimal(new meerkat(0)); // Add three baby meerkats, aged 0.
			}
			born = true;
			break;
		}
		// If no meerkats were born, give below message.
		std::cout << "There are no meerkats able to have children."
				  << std::endl;
		break;
	default:
		std::cout << "error in animal born random roll." << std::endl;
		break;
	}
}
/*******************************************************************************
** Function Name: Buy Adult Animals
** Description: Asks the player is they want to buy an adult animal.
*******************************************************************************/
void Zoo::buyAdultAnimal() {
	int choice;

	std::cout << "Would you like to buy an adult animal?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	choice = validateBinaryChoice();

	if (choice == 1) // If yes, then enter purchasing logic.
	{
		std::cout << "What type of animal would you like to buy?" << std::endl;
		std::cout << "1. monkey" << std::endl;
		std::cout << "2. seaotter" << std::endl;
		std::cout << "3. meerkat" << std::endl;
		choice = validateTrinaryChoice();

		switch (choice) {
		case 1:
			if (getBankAccount() < 12000) {
				std::cout << "You don't have enough money to buy a monkey."
						  << std::endl;
				std::cout << "monkeys cost $12,000 and you only have $"
						  << getBankAccount() << std::endl;
			} else {
        makePayment(12000);
        // Subtract monkey cost from bank account.
        addAnimal(new monkey(104));
				std::cout << "monkey purchased for $12,000. You have $"
						  << getBankAccount() << " remaining." << std::endl;
			}
			break;
		case 2:
			if (getBankAccount() < 4000) {
				std::cout << "You don't have enough money to buy a seaotter."
						  << std::endl;
				std::cout << "seaotters cost $4,000 and you only have $"
						  << getBankAccount() << std::endl;
			} else {
        addAnimal(new seaotter(104));
				makePayment(4000);
				std::cout << "seaotter purchased for $4,000. You have $"
						  << getBankAccount() << " remaining." << std::endl;
			}
			break;
		case 3:
			if (getBankAccount() < 500) {
				std::cout << "You don't have enough money to buy a meerkat."
						  << std::endl;
				std::cout << "meerkats cost $500 and you only have $"
						  << getBankAccount() << std::endl;
			} else {
        addAnimal(new meerkat(104));
				makePayment(500);
				std::cout << "meerkat purchased for $500. You have $"
						  << getBankAccount() << " remaining." << std::endl;
			}
			break;
		default:
			std::cout << "Error in buy adult animal function" << std::endl;
			break;
		}
	} else {
		std::cout << "You have chosen not to buy an adult animal." << std::endl;
	}
}
/*******************************************************************************
** Function Name: Play Game
** Description: Main game loop.
*******************************************************************************/
void Zoo::playGame() {
	int choice;
	std::srand(std::time(NULL)); // For random events.

	// Player chooses to play or quit.
	std::cout << "Zoo Tycoon simulator." << std::endl;
	std::cout << "1. Play" << std::endl;
	std::cout << "2. Quit" << std::endl;

	choice = validateBinaryChoice();
	if (choice == 2) {
		std::cout << "Quitting.." << std::endl;
		std::exit(0);
	}

	// If user doesn't quit, enter beginning of game.
	animalPurchaseMenu();

	// For holding certain daily values during game loop.
	int weekCounter = 1;
	int foodCost = 0;
	int profit = 0;

	// Main game loop.
	while (true) {
		std::cout << "----------------------------" << std::endl;
		std::cout << "Week " << weekCounter << ": " << std::endl;

		// Reset boomInAttendanceBonus and profit to 0 before random event
		// occurs for the week.
		attendanceBonus = 0;
		profit = 0;

		printAnimals();

		// All animals age 1 week.
		ageAllAnimals();

		std::cout << "Rolling for random event..." << std::endl;
		randomEvent();
    std::cout<<"After random event ";
    printAnimals();
		std::cout << "Daily Summary: " << std::endl;
		std::cout << "Payoff from animals: $" << calculatePayoff() << std::endl;
		std::cout << "Feeding costs: $" << calculateFeedingCosts() << std::endl;
		if (attendanceBonus != 0) {
			profit =
				((calculatePayoff() - calculateFeedingCosts()) +
				 attendanceBonus);
			std::cout << "Bonus from boom in attendance: $" << attendanceBonus
					  << std::endl;
			std::cout << "Profits for the week: $" << profit << std::endl;
		} else {
			profit = (calculatePayoff() - calculateFeedingCosts());
			std::cout << "Profits for the week: $" << profit << std::endl;
		}
		// Get paid for the week based on net profits.
		getPaid(profit);

		std::cout << "New bank balance: $" << getBankAccount() << std::endl;

		// Prompt user to buy an adult animal.
		buyAdultAnimal();

		std::cout << "Keep playing?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		choice = validateBinaryChoice();

		if (choice == 2) {
			break;
		}

		weekCounter++;
	}

	deleteAnimalArrays();
}
