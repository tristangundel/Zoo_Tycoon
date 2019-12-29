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
#include "zoo.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

// function to set bank balance attribute
void Zoo::setBankBalance(int zooBalance)
{
	bankBalance = zooBalance;
}

// function to set number of tigers attribute
void Zoo::setNumOfTigers(int tigerNumber)
{
	numOfTigers = tigerNumber;
}

// function to set number of penguins attribute
void Zoo::setNumOfPenguins(int penguinNumber)
{
	numOfPenguins = penguinNumber;
}

// function to set number of turtles attribute
void Zoo::setNumOfTurtles(int turtleNumber)
{
	numOfTurtles = turtleNumber;
}

// function to set current tiger array capacity
void Zoo::setTigerArraySize(int arraySize)
{
	tigerArraySize = arraySize;
}

// function to set current penguin array capacity
void Zoo::setPenguinArraySize(int arraySize)
{
	penguinArraySize = arraySize;
}

// function to set current turtle array capacity
void Zoo::setTurtleArraySize(int arraySize)
{
	turtleArraySize = arraySize;
}

// function to create a new tiger array
void Zoo::setTigerArray(int arraySize)
{
	tigerArray = new Tiger *[arraySize];
}

// function to create a new penguin array
void Zoo::setPenguinArray(int arraySize)
{
	penguinArray = new Penguin *[arraySize];
}

// function to create a new turtle array
void Zoo::setTurtleArray(int arraySize)
{
	turtleArray = new Turtle *[arraySize];
}

// function to add a new Tiger object to array of Tigers
void Zoo::addTiger(int age, bool baby)
{
	// resize array if current number of Tigers is equal to array's capacity
	if (getNumOfTigers() == getTigerArraySize())
	{
		resizeTigerArray();
	}
	// add a new Tiger to the array
	int index = getNumOfTigers();      // retrieve index to add new Tiger
	tigerArray[index] = new Tiger;
	tigerArray[index]->setAge(age);    // set age of new Tiger
	int newSize = (index + 1);
	setNumOfTigers(newSize);           // set new size of Tiger array

	// if Tiger was not born in zoo (was purchased) withdraw the cost of a Tiger
	if (!baby)
	{
	int newBankBalance = (getBankBalance()) - 10000;
	setBankBalance(newBankBalance);
	}
}

// function to add a new Penguin object to array of Penguins
void Zoo::addPenguin(int age, bool baby)
{
	// resize array if current number of Penguins is equal to array's capacity
	if (getNumOfPenguins() == getPenguinArraySize())
	{
		resizePenguinArray();
	}
	// add new Penguin to the array
	int index = getNumOfPenguins();    // retrieve index of array to add new Penguin
	penguinArray[index] = new Penguin;
	penguinArray[index]->setAge(age);  // set age of new Penguin
	int newSize = (index + 1);
	setNumOfPenguins(newSize);         // set new size of Penguin array

	// if Penguin was not born in zoo (was purchased) withdraw the cost of a Penguin
	if (!baby)
	{
	int newBankBalance = (getBankBalance()) - 1000;
	setBankBalance(newBankBalance);
	}
}

// function to add a new Turtle object to array of Turtles
void Zoo::addTurtle(int age, bool baby)
{
	// resize array if current number of Turtle is equal to array's capacity
	if (getNumOfTurtles() == getTurtleArraySize())
	{
		resizeTurtleArray();
	}

	// add new Turtle object
  int index = getNumOfTurtles();      // retrieve index of array to add Turtle
  turtleArray[index] = new Turtle;
	turtleArray[index]->setAge(age);    // set age of new Turtle
	int newSize = (index + 1);
	setNumOfTurtles(newSize);           // set new size of Turtle array

	// if Turtle was not born in zoo (was purchased) withdraw the cost of a Penguin
	if (!baby)
	{
		int newBankBalance = (getBankBalance()) - 100;
		setBankBalance(newBankBalance);
	}
}

// function to return bankBalance value
int Zoo::getBankBalance()
{
	return bankBalance;
}

// function to return number of Tigers
int Zoo::getNumOfTigers()
{
	return numOfTigers;
}

// function to return number of Penguins
int Zoo::getNumOfPenguins()
{
	return numOfPenguins;
}

// function to return number of Turtles
int Zoo::getNumOfTurtles()
{
	return numOfTurtles;
}

// function to capacity of Tiger array
int Zoo::getTigerArraySize()
{
	return tigerArraySize;
}

// function to capacity of Penguin array
int Zoo::getPenguinArraySize()
{
	return penguinArraySize;
}

// function to capacity of Turtle array
int Zoo::getTurtleArraySize()
{
	return turtleArraySize;
}

// function to calculate daily cost of all animals in the zoo
int Zoo::getDailyCost()
{
	int dailyCost = 0;
	// loop through Tigers and add daily cost of each
  for (int i=0; i<getNumOfTigers(); i++)
  {
          dailyCost += tigerArray[i]->getBaseFoodCost();
  }
	// loop through Penguins and add daily cost of each
  for (int i=0; i<getNumOfPenguins(); i++)
  {
          dailyCost += penguinArray[i]->getBaseFoodCost();
  }
	// loop through Turtles and add daily cost of each
  for (int i=0; i<getNumOfTurtles(); i++)
  {
          dailyCost += turtleArray[i]->getBaseFoodCost();
  }

	// return cost
	return dailyCost;
}

// function to calculate daily income from all animals in the zoo
int Zoo::getDailyIncome()
{
	int dailyProfit = 0;
	// loop through Tigers and add daily income of each
  for (int i=0; i<getNumOfTigers(); i++)
  {
          dailyProfit += tigerArray[i]->getPayoff();
  }
	// loop through Penguins and add daily cost of each
  for (int i=0; i<getNumOfPenguins(); i++)
  {
          dailyProfit += penguinArray[i]->getPayoff();
  }
	// loop through Turtles and add daily cost of each
  for (int i=0; i<getNumOfTurtles(); i++)
  {
          dailyProfit += turtleArray[i]->getPayoff();
  }
	// return profit
	return dailyProfit;
}

// function to execute one of 4 random events each day (turn) of the game
void Zoo::randomEvent(int choice)
{
	// conditional statements for random event 1: an animal zoo dies from illness
	if (choice == 1)
	{
		// boolean variables to hold if sickness occurs, and if user owns any animals
		bool validSickness = false;
		bool animalsExist = true;

		// check to ensure user owns some animals
		if (((getNumOfTigers()) + (getNumOfPenguins()) + (getNumOfTurtles())) == 0)
		{
			animalsExist = false;
		}
		// randomly select one of three animal types
		int animalChoice = (rand() % 3) + 1;

		// conditional statements for Tiger
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
		//conditional statements for Penguin
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
		// conditional statement for Turtle
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
		// if animal selection results in animal type user doesn't have, display default message
		if (!validSickness)
		{
			std::cout << "\nIt was a typical day at the zoo today, nothing unusual happened.\n" << std::endl;
		}
		// if user does not own any animals display message and prompt user to buy animals
		if (!animalsExist)
		{
			std::cout << "Warning: Your zoo has no animals in it!" << std::endl;
			std::cout << "You need to buy an animal to keep your zoo running!" << std::endl;
		}

	}
	// conditional statements for random event 2: extra attendance results in an increase of profit
	else if (choice == 2)
	{
		std::cout << "There was a boom in attendance at the zoo today! You made extra profits!" << std::endl;
		int bonus = (rand() % 250) + 251;
		int totalBonus = bonus * (getNumOfTigers());
		std::cout << "You made an extra $" << totalBonus <<std::endl;
		int currentBalance = getBankBalance();
		setBankBalance(currentBalance + totalBonus);
	}
	// conditional statements for random event 3: an animal at the zoo has a baby
	else if (choice == 3)
	{
		// check for existing adult Tigers
		bool adultTigers = false;
		for (int i=0; i<getNumOfTigers(); i++)
		{
			if (tigerArray[i]->getAge() >= 3)
			{
				adultTigers = true;
			}
		}
		// check for existing adult Penguins
    bool adultPenguins = false;
    for (int i=0; i<getNumOfPenguins(); i++)
    {
            if (penguinArray[i]->getAge() >= 3)
            {
                    adultPenguins = true;
            }
    }
		// check for existing adult Turtles
    bool adultTurtles = false;
    for (int i=0; i<getNumOfTurtles(); i++)
    {
            if (turtleArray[i]->getAge() >= 3)
            {
                    adultTurtles = true;
            }
    }
		// if user has no animals  display default message for the day (turn)
		if (!adultPenguins && !adultTigers && !adultTurtles)
		{
			std::cout << "\nIt was a typical day at the zoo today, nothing unusual happened.\n" << std::endl;
		}
		else
		{
			bool validOffspring = false;
			while (!validOffspring)
			{
				// randomly choose which type of animal will have offspring
				int animalChoice = (rand() % 3) + 1;

				// conditional statements for Tiger
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
				// conditional statements for Penguin
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
				// conditional statements for Turtle
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
	// conditional statement for random event 4: nothing happens (default)
	else if (choice == 4)
	{
		std::cout << "\nIt was a typical day at the zoo today, nothing unusual happened.\n" << std::endl;
	}
}

// function to resize Tiger array when it reaches capacity
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

// function to resize Penguin array when it reaches capacity
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

// function to resize Turtle array when it reaches capacity
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

// function to increase all animal ages, called during each turn (day) of the game
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

// function to empty zoo information and delete dynamically allocated memory
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

// default constructor for Zoo objects
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
