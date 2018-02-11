#include "stdafx.h"
#include "Playground.h"
using namespace std;

#pragma region Constructors
Playground::Playground()
{}

Playground::~Playground()
{}
#pragma endregion

Playground& Playground::GetInstance()
{
	static Playground instance;
	return instance;
}


#pragma region Drawing functions
void Playground::AddAnimal(Animal &animal)
{
	animals.push_back(&animal);
	Console &console = Console::GetInstance();
	console.createAnimal(animal);
}

/*void Playground::AnimalsDraw()
{
	Console &console = Console::GetInstance();
	console.BufferPrepare();

	for (auto &animal : animals)
		console.BufferWrite(animal->x, animal->y, animal->GetInfo(), animal->color );

	console.BufferToScreen();
}*/

void Playground::AnimalsDoAction()
{
	for (auto &animal : animals)
		animal->DoAction();
}

Animal& Playground::AnimalCollidesWith(Animal& animal)
{
	for (auto checked_animal : animals)
		if ((checked_animal != &animal) && ((int)checked_animal->x == (int)animal.x) && ((int)checked_animal->y == (int)animal.y))
			return *checked_animal;

	return animal;
}



/*void Playground::Simulate()
{
	Console &console = Console::GetInstance();
	console.HideCursor();
	DWORD currentTickCount;
	DWORD lastCalcTickCount = 0;
	DWORD lastFrameTickCount = 0;

	while (!console.KeyPressed(VK_ESCAPE))
	{
		currentTickCount = GetTickCount();	//tickcount in ms

		if (currentTickCount - lastCalcTickCount> 10)	// 100 razy na sekund�
		{
			AnimalsDoAction();
			lastCalcTickCount = GetTickCount();
		}

		if (currentTickCount - lastFrameTickCount > 20 )
		{
			AnimalsDraw();
			lastFrameTickCount = GetTickCount();
		}
	}
}*/

#pragma endregion

