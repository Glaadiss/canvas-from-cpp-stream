#include <iostream>
#include "stdafx.h"
#include "Rabbit.h"

using namespace std;

#pragma region Constructors
Rabbit::Rabbit() : Rabbit("Anonymous", 0, true)
{}

Rabbit::Rabbit(string name) : Rabbit(name, 0, true)
{}

Rabbit::Rabbit(std::string name, int age, bool isMale) : Animal(name, age, isMale)
{
	//color = FOREGROUND_RED;
}

Rabbit::Rabbit(const Rabbit &rabbit) : Animal(rabbit)
{
	//color = FOREGROUND_RED;
}

Rabbit::Rabbit(Rabbit &&rabbit) : Animal(move(rabbit))
{
	//color = FOREGROUND_RED;
}

Rabbit::~Rabbit()
{}
#pragma endregion

#pragma region Operators
Rabbit& Rabbit::operator= (const Rabbit& rabbit)
{
	Animal::operator= (rabbit);
	return *this;
}

Rabbit& Rabbit::operator= (Rabbit &&rabbit)
{
	Animal::operator= (std::move(rabbit));
	return *this;
}
#pragma endregion

#pragma region Metods: Rabbit info
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

#pragma region Metods: Rabbit actions
Animal::Action Rabbit::ActionInfo(int index)
{
	return actionInfo[index];
}

void Rabbit::ActionThinking()
{
	dx = static_cast <float> (rand() % 500);
	dy = static_cast <float> (rand() % 500);
	dt = 10;
}


void Rabbit::ActionSpecial()
{
	/*Console &console = Console::GetInstance();

	if (actionActualFrame == 20)	console.BufferFrameAround(x, y, 0, 0);
	if (actionActualFrame == 80)	console.BufferFrameAround(x, y, 1, 0);*/
}
#pragma endregion
