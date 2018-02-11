#include <iostream>
#include "stdafx.h"
#include "Dog.h"

using namespace std;

#pragma region Constructors
Dog::Dog() : Dog("Anonymous", 0, true, Breed::Mongrel)
{
}

Dog::Dog(string name) : Dog(name, 0, true, Breed::Mongrel)
{
}

Dog::Dog(std::string name, int age, bool isMale, Breed &breed) : Animal(name, age, isMale), breed(breed)
{
	color = 0;
}

Dog::Dog(const Dog &dog) : Animal(dog), breed(dog.breed)
{
	color = 0;
}

Dog::Dog(Dog &&dog) : Animal(move(dog)), breed(dog.breed)
{
	color = 0;
}

Dog::~Dog()
{
}
#pragma endregion

#pragma region Accessors
// Zestaw akcesor�w - setters
void Dog::SetBreed(Breed &breed)
{
	this->breed = breed;
}

// Zestaw akcesor�w - getters
Breed &Dog::GetBreed() const
{
	return breed;
}

int Dog::GetPower() const
{
	return breed.GetPower();
}

int Dog::GetAggresion() const
{
	return breed.GetAggression();
}

#pragma endregion

#pragma region Operators
Dog &Dog::operator=(const Dog &dog)
{
	Animal::operator=(dog);
	breed = dog.breed;
	return *this;
}

Dog &Dog::operator=(Dog &&dog)
{
	Animal::operator=(std::move(dog));
	breed = dog.breed;
	return *this;
}

Dog Dog::operator+(const Dog &dog)
{
	Animal::operator+(dog);

	Dog puppy("puppy, child of " + name + " & " + dog.name, 0, true, Breed::Mongrel);
	return move(puppy);
}
#pragma endregion

#pragma region Metods : Dog info
string Dog::GetInfo()
{
	return "Dog " + GetName() + " [" + actionText + "]";
}

void Dog::PrintInfo()
{
	cout << GetInfo() << endl;
}

string Dog::GetType()
{
	return "dog";
}

#pragma endregion

#pragma region Metods : Dog actions
Animal::Action Dog::ActionInfo(int index)
{
	return actionInfo[index];
}

/*Dog Dog::SimulateFightWith(Dog dog)
{
	Dog clonedDog = *this;
//	clonedDog.SetPower(power - dog.GetPower());
	return move(clonedDog);
}

void Dog::FightWith(Dog& dog)
{
//	int dogPower = breed.GetPower;
//	SetPower(power - dog.GetPower());
//	dog.SetPower(dog.GetPower() - dogPower);
}*/

std::ostream &operator<<(std::ostream &os, const Dog &dog)
{
	os << dog.GetName();
	return os;
}
#pragma endregion
