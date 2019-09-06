#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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
