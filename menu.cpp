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
#include <string>
#include <iostream>

Menu::Menu()
{
	numOfOptions = 2;
	std::string options[2];
	options[0] = "Start";
	options[1] = "End";
	setMenuOptions(2);
	for (int i=0; i<numOfOptions; i++)
	{
		optionsList[i] = options[i];
	}
}

Menu::Menu(int numbers, std::string *options)
{
	setMenuOptions(numbers);
	numOfOptions = numbers;
	for (int i=0; i<numbers; i++)
	{
		optionsList[i] = options[i];
	}
}

void Menu::setMenuOptions(int num)
{
	optionsList = new std::string[num];
}

void Menu::emptyMenuOptions()
{
	delete [] optionsList;
}

void Menu::printMenu(int number)
{
	std::cout << "\nPlease choose from one of the following options:\n\n " << std::endl;
	for (int i=1; i<=number; i+=1)
	{
		int index = i-1;
		std::cout << i << ". ";
		std::cout << optionsList[index] << std::endl;
	}
	std::cout <<"\n\n";
}

bool Menu::validateInput(std::string selection)
{
	bool validInput = false;
	for (int i=1; i<=numOfOptions; i+=1)
	{
		if (selection == (std::to_string(i)))
		{
			validInput = true;
		}
	}
	return validInput;
}

void Menu::makeSelection()
{
	std::string selection;
	std::cout << "Please enter the number of the menu option you'd like to select." << std::endl;
	std::cin >> selection;
	while (!(validateInput(selection)))
	{
		std::cout << "That is not a valid menu option, please select a valid option." << std::endl;
		std::cin.clear();
		std::cin.ignore(80, '\n');
		std::getline(std::cin, selection);
		std::cout << std::endl;
	}
	userSelection = std::stoi(selection);
}

int Menu::getSelection()
{
	return userSelection;
}
