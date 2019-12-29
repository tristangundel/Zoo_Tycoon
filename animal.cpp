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

#include "animal.hpp"

// function to set age variable
void Animal::setAge(int animalAge)
{
	age = animalAge;
}

// function to set adult variable
void Animal::setAdult(bool animalAdult)
{
	adult = animalAdult;
}

// function to set cost variable
void Animal::setCost(int animalCost)
{
	cost = animalCost;
}

// function to set babies variable
void Animal::setBabies(int animalBabies)
{
	babies = animalBabies;
}

// function to set food cost variable
void Animal::setBaseFoodCost(int animalBaseFoodCost)
{
	baseFoodCost = animalBaseFoodCost;
}

// function to set payoff variable
void Animal::setPayoff(int animalPayoff)
{
	payoff = animalPayoff;
}

// function to return age variable
int Animal::getAge()
{
	return age;
}

// function to return adult variable
bool Animal::getAdult()
{
	return adult;
}

// function to return cost variable
int Animal::getCost()
{
	return cost;
}

// function to return babies variable
int Animal::getBabies()
{
	return babies;
}

// function to return food cost variable
int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

// function to return payoff variable
int Animal::getPayoff()
{
	return payoff;
}

// default constructor to build an Animal object
Animal::Animal()
{
	setAge(0);
	setAdult(false);
	setCost(0);
	setBabies(0);
	setBaseFoodCost(10);
	setPayoff(0);
}
