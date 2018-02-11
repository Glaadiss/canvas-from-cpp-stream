#pragma once
#include "Animal.h"

class Cat : public Animal
{
  private:
	const Action actionInfo[5] = {
		{1, "thinking", 1, &Animal::ActionThinking},
		{60, "running", 200, &Animal::ActionMoving},
		{9, "repairing", 300, &Animal::ActionSpecial},
		{30, "sleeping", 100, &Animal::ActionSleeping},
		{0, "collision", 100, &Animal::ActionCollision}};

  public:
	// konstruktory
	Cat();
	Cat(const Cat &cat);
	Cat(Cat &&cat);
	Cat(std::string name);
	Cat(std::string name, int age, bool isMale);
	~Cat();

	// Operatory
	Cat &operator=(const Cat &cat);
	Cat &operator=(Cat &&cat);

	// Cat acctions
	virtual Action ActionInfo(int index);
	virtual void ActionThinking();
	virtual void ActionSpecial();

	// Pozosta�e metody
	virtual std::string GetInfo();
	virtual void PrintInfo();
	virtual std::string GetType();
};
