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
#include "turtle.hpp"

// constructor to create a Turtle object
Turtle::Turtle()
{
	setAge(1);
	setAdult(false);
	setCost(100);
	setBabies(10);
	setBaseFoodCost(5);
	setPayoff(5);
}
