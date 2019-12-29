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
#ifndef MENU_HPP
#define MENU_HPP
#include <string>

class Menu
{
	private:
		int numOfOptions;
		std::string *optionsList;
		int userSelection;
	public:
		Menu();
		Menu(int, std::string *options);
		void printMenu(int);
		bool validateInput(std::string);
		void makeSelection();
		int getSelection();
		void setMenuOptions(int);
		void emptyMenuOptions();
};

#endif
