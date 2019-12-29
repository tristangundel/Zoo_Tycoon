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
#ifndef ZOO_HPP
#define ZOO_HPP
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"

/* This class will hold the zoo's arrays of animals objects, as well as
the user's bank balance. It will also contain methods to update these
variables that will be used in the main function of the application */
class Zoo
{
	private:
		int numOfTigers;
		int numOfPenguins;
		int numOfTurtles;
		int bankBalance;
		int tigerArraySize;
		int penguinArraySize;
		int turtleArraySize;
		Tiger **tigerArray;
		Turtle **turtleArray;
		Penguin **penguinArray;
	public:
		void setBankBalance(int);
		void setNumOfTigers(int);
		void setNumOfPenguins(int);
		void setNumOfTurtles(int);
		void setTigerArraySize(int);
		void setPenguinArraySize(int);
		void setTurtleArraySize(int);
		void setTigerArray(int);
		void setPenguinArray(int);
		void setTurtleArray(int);
		void addTiger(int, bool);
		void addPenguin(int, bool);
		void addTurtle(int, bool);
		int getBankBalance();
		int getNumOfTigers();
		int getNumOfPenguins();
		int getNumOfTurtles();
		int getTigerArraySize();
		int getPenguinArraySize();
		int getTurtleArraySize();
		int getDailyCost();
		int getDailyIncome();
		void randomEvent(int);
		void resizeTigerArray();
		void resizePenguinArray();
		void resizeTurtleArray();
		void increaseAnimalAges();
		void emptyZooInfo();
		Zoo();
};

#endif
