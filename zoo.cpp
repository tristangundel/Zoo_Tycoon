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
#include "zoo.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void Zoo::setBankBalance(int zooBalance)
{
	bankBalance = zooBalance;
}

void Zoo::setNumOfTigers(int tigerNumber)
{
	numOfTigers = tigerNumber;
}

void Zoo::setNumOfPenguins(int penguinNumber)
{
	numOfPenguins = penguinNumber;
}

void Zoo::setNumOfTurtles(int turtleNumber)
{
	numOfTurtles = turtleNumber;
}

void Zoo::setTigerArraySize(int arraySize)
{
	tigerArraySize = arraySize;
}

void Zoo::setPenguinArraySize(int arraySize)
{
	penguinArraySize = arraySize;
}

void Zoo::setTurtleArraySize(int arraySize)
{
	turtleArraySize = arraySize;
}

void Zoo::setTigerArray(int arraySize)
{
	tigerArray = new Tiger *[arraySize];
}

void Zoo::setPenguinArray(int arraySize)
{
	penguinArray = new Penguin *[arraySize];
}

void Zoo::setTurtleArray(int arraySize)
{
	turtleArray = new Turtle *[arraySize];
}

void Zoo::addTiger(int age, bool baby)
{
	if (getNumOfTigers() == getTigerArraySize())
	{
		resizeTigerArray();
	}
	int index = getNumOfTigers();
	tigerArray[index] = new Tiger;
	tigerArray[index]->setAge(age);
	int newSize = (index + 1);
	setNumOfTigers(newSize);
	if (!baby)
	{
	int newBankBalance = (getBankBalance()) - 10000; 
	setBankBalance(newBankBalance);
	}
}

void Zoo::addPenguin(int age, bool baby)
{
	if (getNumOfPenguins() == getPenguinArraySize())
	{
		resizePenguinArray();
	}
	int index = getNumOfPenguins();
	penguinArray[index] = new Penguin;
	penguinArray[index]->setAge(age);
	int newSize = (index + 1);
	setNumOfPenguins(newSize);
	if (!baby)
	{
	int newBankBalance = (getBankBalance()) - 1000;
	setBankBalance(newBankBalance);
	}
}

void Zoo::addTurtle(int age, bool baby)
{
	if (getNumOfTurtles() == getTurtleArraySize())
	{
		resizeTurtleArray();
	}
        int index = getNumOfTurtles();
        turtleArray[index] = new Turtle;
	turtleArray[index]->setAge(age);
        int newSize = (index + 1);
        setNumOfTurtles(newSize);
	if (!baby)
	{
		int newBankBalance = (getBankBalance()) - 100;
		setBankBalance(newBankBalance);
	}
}

int Zoo::getBankBalance()
{
	return bankBalance;
} 

int Zoo::getNumOfTigers()
{
	return numOfTigers;
}

int Zoo::getNumOfPenguins()
{
	return numOfPenguins;
}

int Zoo::getNumOfTurtles()
{
	return numOfTurtles;
}

int Zoo::getTigerArraySize()
{
	return tigerArraySize;
}

int Zoo::getPenguinArraySize()
{
	return penguinArraySize;
}

int Zoo::getTurtleArraySize()
{
	return turtleArraySize;
}

int Zoo::getDailyCost()
{
	int dailyCost = 0;
        for (int i=0; i<getNumOfTigers(); i++)
        {
                dailyCost += tigerArray[i]->getBaseFoodCost();
        }
        for (int i=0; i<getNumOfPenguins(); i++)
        {
                dailyCost += penguinArray[i]->getBaseFoodCost();
        }
        for (int i=0; i<getNumOfTurtles(); i++)
        {
                dailyCost += turtleArray[i]->getBaseFoodCost();
        }
	return dailyCost;
}

int Zoo::getDailyIncome()
{
	int dailyProfit = 0;
        for (int i=0; i<getNumOfTigers(); i++)
        {
                dailyProfit += tigerArray[i]->getPayoff();
        }
        for (int i=0; i<getNumOfPenguins(); i++)
        {
                dailyProfit += penguinArray[i]->getPayoff();
        }
        for (int i=0; i<getNumOfTurtles(); i++)
        {
                dailyProfit += turtleArray[i]->getPayoff();
        }
	return dailyProfit;
}

void Zoo::randomEvent(int choice)
{
	if (choice == 1)
	{
		bool validSickness = false; 
		bool animalsExist = true;
		if (((getNumOfTigers()) + (getNumOfPenguins()) + (getNumOfTurtles())) == 0)
		{
			animalsExist = false;
		}
		int animalChoice = (rand() % 3) + 1;
		if (animalChoice == 1)
		{
			int tigers = getNumOfTigers();
			if (tigers > 0)
			{
				std::cout << "Sadly one of your tigers got sick and died today" << std::endl;
				delete tigerArray[(getNumOfTigers() - 1)];
				setNumOfTigers((getNumOfTigers() - 1));
				validSickness = true;
			}
		}
		else if (animalChoice == 2)
		{
			int penguins = getNumOfPenguins();
			if (penguins > 0)
			{
    	                	std::cout << "Unfortunately one of your penguins got sick and died today" << std::endl;
                        	delete penguinArray[(getNumOfPenguins() - 1)];
       	                	setNumOfPenguins((getNumOfPenguins() - 1));
				validSickness = true;
			}
		}
		else if (animalChoice == 3)
		{
			int turtles = getNumOfTurtles();
			if (turtles > 0)
			{
                       		std::cout << "Unfortunately one of your turtles got sick and died today" << std::endl;
                       		delete turtleArray[(getNumOfTurtles() - 1)];
                       		setNumOfTurtles((getNumOfTurtles() - 1));
				validSickness = true;
			}
		}
		if (!validSickness)
		{
			std::cout << "\nIt was a typical day at the zoo today, nothing unusual happened.\n" << std::endl;
		}
		if (!animalsExist)
		{
			std::cout << "Warning: Your zoo has no animals in it!" << std::endl;
			std::cout << "You need to buy an animal to keep your zoo running!" << std::endl;
		}
		
	}
	else if (choice == 2)
	{
		std::cout << "There was a boom in attendance at the zoo today! You made extra profits!" << std::endl;
		int bonus = (rand() % 250) + 251;
		int totalBonus = bonus * (getNumOfTigers());
		std::cout << "You made an extra $" << totalBonus <<std::endl;
		int currentBalance = getBankBalance();  		
		setBankBalance(currentBalance + totalBonus);
	}
	else if (choice == 3)
	{
		bool adultTigers = false;
		for (int i=0; i<getNumOfTigers(); i++)
		{
			if (tigerArray[i]->getAge() >= 3)
			{
				adultTigers = true;
			} 
		}
                bool adultPenguins = false;
                for (int i=0; i<getNumOfPenguins(); i++)
                {
                        if (penguinArray[i]->getAge() >= 3)
                        {
                                adultPenguins = true;
                        }
                }
                bool adultTurtles = false;
                for (int i=0; i<getNumOfTurtles(); i++)
                {
                        if (turtleArray[i]->getAge() >= 3)
                        {
                                adultTurtles = true;
                        }
                }
		if (!adultPenguins && !adultTigers && !adultTurtles)
		{
			std::cout << "\nIt was a typical day at the zoo today, nothing unusual happened.\n" << std::endl; 	
		}
		else
		{
			bool validOffspring = false;
			while (!validOffspring)
			{
				int animalChoice = (rand() % 3) + 1;
				if ((animalChoice == 1) && (adultTigers))
				{
					std::cout << "One of your tigers had a baby today!" << std::endl; 
					int numOfBabies = tigerArray[0]->getBabies();
					for (int i=0; i<numOfBabies; i++)
					{
						addTiger(0, true);
					} 
                                        validOffspring = true;
				}
                                if ((animalChoice == 2) && (adultPenguins))
                                {
					std::cout << "One of your penguins had 5 babies today!" << std::endl;
                                        int numOfBabies = penguinArray[0]->getBabies();
                                        for (int i=0; i<numOfBabies; i++)
                                        {
                                                addPenguin(0, true);
                                        }
                                        validOffspring = true;
                                }
                                if ((animalChoice == 3) && (adultTurtles))
                                {
					std::cout << "One of your turtles had 10 babies today!" << std::endl;
                                        int numOfBabies = turtleArray[0]->getBabies();
                                        for (int i=0; i<numOfBabies; i++)
                                        {
                                                addTurtle(0, true);
                                        }
					validOffspring = true;
                                }
			}
		}
	}
	else if (choice == 4)
	{
		std::cout << "\nIt was a typical day at the zoo today, nothing unusual happened.\n" << std::endl;
	}
}

void Zoo::resizeTigerArray()
{
	int newSize = ((getTigerArraySize()) * 2);
	Tiger *tempArray[getTigerArraySize()];
	for (int i=0; i<getTigerArraySize(); i++)
	{
		tempArray[i] = tigerArray[i];
	}
	delete [] tigerArray;
	setTigerArray(newSize);
	for (int i=0; i<getTigerArraySize(); i++)
	{
		tigerArray[i] = tempArray[i];
	}
	setTigerArraySize(newSize);
}

void Zoo::resizePenguinArray()
{
        int newSize = ((getPenguinArraySize()) * 2);
        Penguin *tempArray[getPenguinArraySize()];
        for (int i=0; i<getPenguinArraySize(); i++)
        {
                tempArray[i] = penguinArray[i];
        }
        delete [] penguinArray;
	setPenguinArray(newSize);
        for (int i=0; i<getPenguinArraySize(); i++)
        {
                penguinArray[i] = tempArray[i];
        }
        setPenguinArraySize(newSize);
}

void Zoo::resizeTurtleArray()
{
        int newSize = ((getTurtleArraySize()) * 2);
        Turtle *tempArray[getTurtleArraySize()];
        for (int i=0; i<getTurtleArraySize(); i++)
        {
                tempArray[i] = turtleArray[i];
        }
        delete [] turtleArray;
        setTurtleArray(newSize);
        for (int i=0; i<getTurtleArraySize(); i++)
        {
                turtleArray[i] = tempArray[i];
        }
        setTurtleArraySize(newSize);
}

void Zoo::increaseAnimalAges()
{
	for (int i=0; i<getNumOfTigers(); i++)
        {
		int currentAge = tigerArray[i]->getAge();
                tigerArray[i]->setAge(currentAge + 1);
        }
        for (int i=0; i<getNumOfPenguins(); i++)
        {
		int currentAge = penguinArray[i]->getAge();
		penguinArray[i]->setAge(currentAge + 1);
        }
        for (int i=0; i<getNumOfTurtles(); i++)
        {
		int currentAge = turtleArray[i]->getAge();
                turtleArray[i]->setAge(currentAge + 1);
        }
}

void Zoo::emptyZooInfo()
{
	for (int i=0; i<getNumOfTigers(); i++)
	{
		delete tigerArray[i];
	} 
        for (int i=0; i<getNumOfPenguins(); i++)
        {
                delete penguinArray[i];
        }
        for (int i=0; i<getNumOfTurtles(); i++)
        {
                delete turtleArray[i];
        }
	delete [] tigerArray;
	delete [] penguinArray;
	delete [] turtleArray;
}

Zoo::Zoo()
{
	setTigerArraySize(10);
	setPenguinArraySize(10);
	setTurtleArraySize(10);
	setTigerArray(10);
	setPenguinArray(10);
	setTurtleArray(10);
	setNumOfTigers(0);
	setNumOfPenguins(0);
	setNumOfTurtles(0);
	setBankBalance(50000);
}


