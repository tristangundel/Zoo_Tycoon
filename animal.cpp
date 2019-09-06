/*********************************************************************
** Program name: zooTycoon
** Author: Tristan Gundel
** Date: 10/22/2018
** Description: This file is one of 11 files that together form a program
**              with the capability of running a simulation of the game 
**              zoo tycoon. The game will allow the user to purchase 
**              animals, and will keep track of the user's bank balance, 
**              adding to it and subtracting to it accordingly. A random   
**              event will occur each turn (day) of the game.  
*********************************************************************/

#include "animal.hpp"

void Animal::setAge(int animalAge)
{
	age = animalAge;
}

void Animal::setAdult(bool animalAdult)
{
	adult = animalAdult;
}

void Animal::setCost(int animalCost)
{
	cost = animalCost;
}

void Animal::setBabies(int animalBabies)
{
	babies = animalBabies;
}

void Animal::setBaseFoodCost(int animalBaseFoodCost)
{
	baseFoodCost = animalBaseFoodCost;
}

void Animal::setPayoff(int animalPayoff)
{
	payoff = animalPayoff;
}

int Animal::getAge()
{
	return age;
}

bool Animal::getAdult()
{
	return adult;
}

int Animal::getCost()
{
	return cost;
}

int Animal::getBabies()
{
	return babies;
}

int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

int Animal::getPayoff()
{
	return payoff;
}

Animal::Animal()
{
	setAge(0);
	setAdult(false);
	setCost(0);
	setBabies(0);
	setBaseFoodCost(10);
	setPayoff(0);
}

