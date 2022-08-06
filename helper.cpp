/*******************************************************************************
** Program: zoo_tycoon.cpp
** Author:
** Date:
** Description: Helper functions for the other classes to utilize.
*******************************************************************************/
#include <iostream>
/*******************************************************************************
** Function Name: validateBinaryChoice
** Description: This is an input validation loop for a binary choice (1 or 2)
** to make validating user input more efficient. Accepts 1 or 2 and returns
** that int. Used for main menu choice and type of die choice.
*******************************************************************************/
int validateBinaryChoice() {
	int input;
	do {
		std::cout << "Please enter your choice: \n";
		std::cin >> input;

		if (std::cin.fail()) {
			std::cout << "Invalid input. Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (std::cin.fail() || input < 1 || input > 2);

	return input;
}
/*******************************************************************************
** Function Name: validatePurchaseChoice
** Description: This is an input validation loop for the animal purchasing menu.
** Only allows the user to submit 1, 2 or 3.
*******************************************************************************/
int validateTrinaryChoice() {
	int input;
	do {
		std::cout << "Please enter your choice: \n";
		std::cin >> input;

		if (std::cin.fail()) {
			std::cout << "Invalid input. Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (std::cin.fail() || input < 1 || input > 3);

	return input;
}