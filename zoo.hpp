#ifndef ZOO_HPP
#define ZOO_HPP
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"


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
