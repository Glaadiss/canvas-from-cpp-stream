#include "stdafx.h"
#include "Cat.h"
#include <iostream>

using namespace std;

#pragma region Constructors
Cat::Cat() : Cat("Anonymous", 0, true)
{
}

Cat::Cat(string name) : Cat(name, 0, true)
{
}

Cat::Cat(std::string name, int age, bool isMale) : Animal(name, age, isMale) {}

Cat::Cat(const Cat &cat) : Animal(cat) {}

Cat::Cat(Cat &&cat) : Animal(move(cat)) {}

Cat::~Cat() {}

#pragma endregion

#pragma region Operators
Cat &Cat::operator=(const Cat &cat)
{
	Animal::operator=(cat);
	return *this;
}

Cat &Cat::operator=(Cat &&cat)
{
	Animal::operator=(std::move(cat));
	return *this;
}
#pragma endregion

#pragma region Metods : Rabbit info
string Cat::GetInfo()
{
	return "Cat " + GetName() + " [" + actionText + "]";
}

void Cat::PrintInfo()
{
	cout << GetInfo() << endl;
}

string Cat::GetType()
{
	return "cat";
}
#pragma endregion

#pragma region Metods : Cat actions
Animal::Action Cat::ActionInfo(int index)
{
	return actionInfo[index];
}

#pragma endregion
