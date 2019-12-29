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
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/* this class will serve as the base class for the 3 different
animals that will be used in the game */
class Animal
{
	protected:
		int age;
		bool adult;
		int cost;
		int babies;
		int baseFoodCost;
		int payoff;
	public:
		void setAge(int);
		void setAdult(bool);
		void setCost(int);
		void setBabies(int);
		void setBaseFoodCost(int);
		void setPayoff(int);
		int getAge();
		bool getAdult();
		int getCost();
		int getBabies();
		int getBaseFoodCost();
		int getPayoff();
		Animal();
};

#endif
