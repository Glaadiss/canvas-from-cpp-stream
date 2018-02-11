#pragma once
#include "Animal.h"
#include <string>

class Rabbit : public Animal
{
  private:
	const Action actionInfo[5] = {
		{1, "thinking", 1, &Animal::ActionThinking},
		{60, "jumping", 200, &Animal::ActionMoving},
		{20, "eating", 100, &Animal::ActionSpecial},
		{19, "sleeping", 100, &Animal::ActionSleeping}};

  public:
	// konstruktory
	Rabbit();
	Rabbit(const Rabbit &rabbit);
	Rabbit(Rabbit &&rabbit);
	Rabbit(std::string name);
	Rabbit(std::string name, int age, bool isMale);
	~Rabbit();

	// Operatory
	Rabbit &operator=(const Rabbit &dog);
	Rabbit &operator=(Rabbit &&dog);

	// Rabbit acctions
	virtual Action ActionInfo(int index);

	// Pozosta�e metody
	virtual std::string GetInfo();
	virtual void PrintInfo();
	virtual std::string GetType();
};
