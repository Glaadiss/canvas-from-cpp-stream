#include <iostream>
#include "stdafx.h"
#include "Rabbit.h"

using namespace std;

#pragma region Constructors
Rabbit::Rabbit() : Rabbit("Anonymous", 0, true)
{
}

Rabbit::Rabbit(string name) : Rabbit(name, 0, true) {}

Rabbit::Rabbit(std::string name, int age, bool isMale) : Animal(name, age, isMale) {}

Rabbit::Rabbit(const Rabbit &rabbit) : Animal(rabbit) {}

Rabbit::Rabbit(Rabbit &&rabbit) : Animal(move(rabbit)) {}

Rabbit::~Rabbit() {}

#pragma endregion

#pragma region Operators
Rabbit &Rabbit::operator=(const Rabbit &rabbit)
{
	Animal::operator=(rabbit);
	return *this;
}

Rabbit &Rabbit::operator=(Rabbit &&rabbit)
{
	Animal::operator=(std::move(rabbit));
	return *this;
}
#pragma endregion

#pragma region Metods : Rabbit info
string Rabbit::GetInfo()
{
	return "Rabbit " + GetName() + "[" + actionText + "]";
}

void Rabbit::PrintInfo()
{
	cout << GetInfo() << endl;
}

string Rabbit::GetType()
{
	return "rabbit";
}
#pragma endregion

#pragma region Metods : Rabbit actions
Animal::Action Rabbit::ActionInfo(int index)
{
	return actionInfo[index];
}

#pragma endregion
