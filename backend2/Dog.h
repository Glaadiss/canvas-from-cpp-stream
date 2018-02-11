#pragma once
#include "Breed.h"
#include "Animal.h"

class Dog : public Animal
{
private:
	const Action actionInfo[5] = {
		{ 1, "thinking", 1, &Animal::ActionThinking },
		{ 60, "running", 200, &Animal::ActionMoving },
		{ 20, "pissing", 100, &Animal::ActionSpecial },
		{ 19, "sleeping", 100, &Animal::ActionSleeping },
		{ 0, "collision", 100, &Animal::ActionCollision }
	};

	Breed &breed;
	friend std::ostream& operator<< (std::ostream& os, const Dog& foo);

public:
	// konstruktory
	Dog();
	Dog(const Dog &dog);
	Dog(Dog &&dog);
	Dog(std::string name);
	Dog(std::string name, int age, bool isMale, Breed &breed);
	~Dog();

	// Akcesory - setters
	void SetBreed(Breed &breed);

	// Akcesory - getters
	Breed& GetBreed() const;
	int GetPower() const;
	int GetAggresion() const;

	// Operatory
	Dog& operator= (const Dog& dog); 
	Dog& operator= (Dog&& dog); 
	Dog operator+(const Dog &dog);		
									
	// Dog acctions
	virtual Action ActionInfo(int index);
	virtual void ActionThinking();
	
	// Pozosta�e metody
	virtual std::string GetInfo();
	virtual void PrintInfo();
	virtual std::string GetType();

	Dog SimulateFightWith(Dog);
	void FightWith(Dog& dog);
};

