#include <iostream>
#include "stdafx.h"
#include "Console.h"

// DO ZROBIENIA OD NOWA

using json = nlohmann::json;

Console::Console() {}
Console::~Console() {}

Console &Console::GetInstance()
{
	static Console instance;
	return instance;
}

void Console::createAnimal(Animal &animal)
{

	json newAnimal = {
		{"eventName", "newAnimal"},
		{
			"eventData",
			{
				{"name", animal.GetName()},
				{"type", animal.GetType()},
				{"x", animal.x},
				{"y", animal.y},
			},
		},
	};

	std::cout << newAnimal.dump() << std::flush;
}

void Console::moveAnimal(Animal &animal)
{
	json move = {
		{"eventName", "move"},
		{
			"eventData",
			{
				{"name", animal.GetName()},
				{"x", animal.x},
				{"y", animal.y},
			},
		},
	};

	std::cout << move.dump() << std::flush;
}

void Console::specialAction(Animal &animal)
{
	json special = {
		{"eventName", "special"},
		{
			"eventData",
			{
				{"name", animal.GetName()},
				{"type", animal.GetType()},
			},
		},
	};

	std::cout << special.dump() << std::flush;
}

void Console::animalSleeping(Animal &animal)
{
	json special = {
		{"eventName", "sleep"},
		{
			"eventData",
			{
				{"name", animal.GetName()},
			},
		},
	};

	std::cout << special.dump() << std::flush;
}

void Console::animalThinking(Animal &animal)
{
	json special = {
		{"eventName", "think"},
		{
			"eventData",
			{
				{"name", animal.GetName()},
			},
		},
	};

	std::cout << special.dump() << std::flush;
}

int Console::GetWidth()
{
	return width;
}

int Console::GetHeight()
{
	return height;
}