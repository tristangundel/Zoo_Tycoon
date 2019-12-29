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
#include "tiger.hpp"

// constructor to create a Tiger object
Tiger::Tiger()
{
	setAge(1);
	setAdult(false);
	setCost(10000);
	setBabies(1);
	setBaseFoodCost(50);
	setPayoff(2000);
}
