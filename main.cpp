/*********************************************************************
** Program name: zooTycoon
** Author: Tristan Gundel
** Date: 10/22/2018
** Description: This file is one of 13 files that together form a program
**              with the capability of running a simulation of the game
**              zoo tycoon. The game will allow the user to purchase
**              animals, and will keep track of the user's bank balance,
**              adding to it and subtracting to it accordingly. A random
**              event will occur each turn (day) of the game.
*********************************************************************/
#include "menu.hpp"
#include "zoo.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	//Initialize Zoo and write Introduction message to console
	srand(time(NULL));
	Zoo myZoo;
	std::cout << "\n\nWelcome to Zoo Tycoon!!!\n" << std::endl;
	std::cout << "Today you will begin with $50,000 in your zoo's bank account "
	          << "to begin buying animals and creating your zoo.\n" << std::endl;

	//Initialize startMenu with options for buying one or two animals to start
	std::string startMenuOptions[2];
	startMenuOptions[0] = "Buy One";
	startMenuOptions[1] = "Buy Two";
	Menu startMenu(2, &startMenuOptions[0]);

	//Get User selection for number of animals to start with in the zoo
	std::cout << "\nTigers will cost $10,000 with a daily payoff of $2000." << std::endl;
	std::cout << "How many tigers would you like to buy for the opening of your zoo?\n" << std::endl;
	startMenu.printMenu(2);
	startMenu.makeSelection();
	for (int i=0; i<(startMenu.getSelection()); i++)
	{
		myZoo.addTiger(1, false);
	}
        std::cout << "\nPenguins will cost $1,000 with a daily payoff of $100." << std::endl;
        std::cout << "How many penguins would you like to buy for the opening of your zoo?\n" << std::endl;
        startMenu.printMenu(2);
        startMenu.makeSelection();
        for (int i=0; i<(startMenu.getSelection()); i++)
        {
                myZoo.addPenguin(1, false);
        }
        std::cout << "\nTurtles will cost $100, with a daily payoff of $5." << std::endl;
        std::cout << "How many turtles would you like to buy for the opening of your zoo?\n" << std::endl;
        startMenu.printMenu(2);
        startMenu.makeSelection();
        for (int i=0; i<(startMenu.getSelection()); i++)
        {
                myZoo.addTurtle(1, false);
        }

	//Display bank balance after buying initial animals
	std::cout << "After buying your first animals the balance in your Zoo's bank account is $"
		  << myZoo.getBankBalance() << std::endl;

	//Setup mainMenu to display after each turn (day) of the game
	std::string mainMenuOptions[3];
	mainMenuOptions[0] = "Buy an adult animal";
	mainMenuOptions[1] = "Continue on to the next day";
	mainMenuOptions[2] = "Exit the Game";
	Menu mainMenu(3, &mainMenuOptions[0]);

	//Setup animalMenu to display if user wants to buy and adult animal
	std::string animalMenuOptions[3];
	animalMenuOptions[0] = "Buy an adult Tiger";
	animalMenuOptions[1] = "Buy an adult Penguin";
	animalMenuOptions[2] = "Buy an adult Turtle";
	Menu animalMenu(3, &animalMenuOptions[0]);

	int dayCount = 1;
	do
	{
		std::cout << "\nDay " << dayCount << ":\n" << std::endl;

		//increase Animal ages
		myZoo.increaseAnimalAges();

		//Deduct feeding cost of animals
		int costOfFood = myZoo.getDailyCost();
		int currentBalance = myZoo.getBankBalance();
		myZoo.setBankBalance((currentBalance - costOfFood));
		std::cout << "After feeding your animals today your bank balance is now "
		          << myZoo.getBankBalance() << std::endl;

		//Random event occurs
		int randomEvent = (rand() % 4) + 1;
		myZoo.randomEvent(randomEvent);

		//Add Payoff of the day to the zoo bank balance
		int payoffOfTheDay = myZoo.getDailyIncome();
		currentBalance = myZoo.getBankBalance();
		myZoo.setBankBalance(currentBalance + payoffOfTheDay);
		std::cout << "After calculating the profits of the day you bank balance is now "
		          << myZoo.getBankBalance() << std::endl;

		//Print main menu for user
		mainMenu.printMenu(3);
		mainMenu.makeSelection();

		//Buy an adult animal if the user chooses to do so
		if (mainMenu.getSelection() == 1)
		{
			animalMenu.printMenu(3);
			animalMenu.makeSelection();
			if (animalMenu.getSelection() == 1)
			{
				myZoo.addTiger(3, false);
			}
			else if (animalMenu.getSelection() == 2)
			{
				myZoo.addPenguin(3, false);
			}
			else if (animalMenu.getSelection() == 3)
			{
				myZoo.addTurtle(3, false);
			}
		}

		//Increase day count
		dayCount += 1;
	}
	while (!(mainMenu.getSelection() == 3) && (myZoo.getBankBalance() > 0));

	//Print exit messages
	if (myZoo.getBankBalance() <= 0)
	{
		std::cout << "\n\nSorry, but you don't have enough funds to keep your zoo running." << std::endl;
	}
	std::cout << "\nExiting the game now. Good-Bye!" << std::endl;

	//Clear all dynamically allocated memory
	myZoo.emptyZooInfo();
	startMenu.emptyMenuOptions();
	mainMenu.emptyMenuOptions();
	animalMenu.emptyMenuOptions();
	return 0;
}
