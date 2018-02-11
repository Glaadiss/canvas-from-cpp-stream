#include <iostream>
#include "stdafx.h"
#include "Animal.h"
#include "Playground.h"

using namespace std;

#pragma region Constructors
Animal::Animal() : Animal("Anonymous", 0, true)
{
}

Animal::Animal(std::string name) : Animal(name, 0, true) // constructor delegation
{
}

Animal::Animal(std::string name, int age, bool isMale) : name(name), age(age), isMale(isMale)
{
	x = static_cast<float>(150 + rand() % 800);
	y = static_cast<float>(150 + rand() % 600);
}

Animal::Animal(const Animal &animal)
{
	x = animal.x;
	y = animal.y;

	if (animal.imageData)
	{
		imageData = new char[strlen(animal.imageData) + 1];
		memcpy(imageData, animal.imageData, strlen(animal.imageData) + 1);
	}
}

Animal::Animal(Animal &&animal) : name(animal.name), age(animal.age), isMale(animal.isMale), imageData(animal.imageData)
{
	x = animal.x;
	y = animal.y;

	animal.imageData = nullptr;
}

Animal::~Animal()
{
	if (imageData)
		delete[] imageData;
}
#pragma endregion

#pragma region Accessors
// Akcesory - setters
void Animal::SetName(std::string name)
{
	this->name = name;
	cout << GetName() << " name modified to " << this->name << " by setter function" << endl;
}

void Animal::SetAge(int age)
{
	this->age = age;
	cout << GetName() << " age modified to " << this->age << " by setter function" << endl;
}

void Animal::SetImage(char *imageData)
{
	cout << name << " image modified to " << imageData << " by setter function" << endl;
	if (this->imageData) // != nullptr
		delete[] imageData;

	if (imageData)
	{
		this->imageData = new char[strlen(imageData) + 1];
		strcpy(this->imageData, imageData);
	}
}

// Akcesory - getters
std::string Animal::GetName() const
{
	return name.empty() ? "Anonymous" : name;
}

int Animal::GetAge() const
{
	return age;
}

char *Animal::GetImage() const
{
	return imageData;
}

#pragma endregion

#pragma region Operators
Animal &Animal::operator=(const Animal &animal)
{
	if (imageData)
	{
		delete[] imageData;
		imageData = nullptr;
	}

	if (animal.imageData)
	{
		imageData = new char[strlen(animal.imageData) + 1];
		memcpy(imageData, animal.imageData, strlen(animal.imageData) + 1);
	}

	name = animal.name;
	age = animal.age;
	isMale = animal.isMale;

	return *this;
}

Animal &Animal::operator=(Animal &&animal)
{
	if (imageData)
		delete[] imageData;

	imageData = animal.imageData;
	animal.imageData = nullptr;

	name = animal.name;
	age = animal.age;
	isMale = animal.isMale;

	return *this;
}

Animal &Animal::operator++()
{
	age++;
	return *this;
}

Animal Animal::operator++(int)
{
	Animal oldAnmial = *this;
	age++;
	return move(oldAnmial);
}

Animal Animal::operator+(const Animal &animal)
{
	if (isMale == animal.isMale)
		exit(1);

	Animal puppy("puppy, child of " + name + " & " + animal.name, 0, true);
	return move(puppy);
}
#pragma endregion

#pragma region Class methods
void Animal::DoAction()
{
	Action action = ActionInfo(0);
	int random_number = rand() % 100;
	int newFunctionIndex = 0;
	int sum = action.probability;

	while (random_number > sum)
	{
		action = ActionInfo(++newFunctionIndex);
		sum += action.probability;
	}

	currentActionFunction = action.actionFunction;
	actionText = action.actionText;

	(this->*currentActionFunction)();
}

Animal::Action Animal::ActionInfo(int index)
{
	return Action{0, "fake", 0, nullptr};
}

void Animal::ActionThinking()
{
	Console &console = Console::GetInstance();
	console.animalThinking(*this);
}
void Animal::ActionSpecial()
{
	Console &console = Console::GetInstance();
	console.specialAction(*this);
}
void Animal::ActionSleeping()
{
	Console &console = Console::GetInstance();
	console.animalSleeping(*this);
}

void Animal::ActionMoving()
{

	Console &console = Console::GetInstance();

	int dx = 5 + (rand() % (console.GetWidth() - 50));
	int dy = 5 + (rand() % (console.GetHeight() - 20));

	x = dx;
	y = dy;

	console.moveAnimal(*this);
}

string Animal::GetInfo()
{
	string imageDesc = imageData ? imageData : "no data";
	string liveDesc = isAlive ? "" : "Dead";
	string infoString = liveDesc + name + " age " + std::to_string(age) + " image " + imageDesc;
	return infoString;
}

void Animal::PrintInfo()
{
	cout << GetInfo() << endl;
}

std::string Animal::GetType() {}

#pragma endregion
