#pragma once
#include <string>

class Animal
{
  public:
	// step characterists
	float x, y;   // current position
	float dx, dy; // surrent speed (in 1/100s)
	int dt;		  // jump characteristics

	short color = 0;
	int actionActualFrame = 0;
	int actionFrameNumber = 1;

  protected:
	typedef void (Animal::*ActionFunction)();
	struct Action
	{
		int probability;
		std::string actionText;
		int frameNumber;
		ActionFunction actionFunction;
	};
	ActionFunction currentActionFunction = &Animal::ActionThinking;

	std::string name;
	std::string actionText;
	int age = 0;
	bool isMale = true;
	bool isAlive = true;
	char *imageData = nullptr;

  public:
	// Constructors and destructor
	Animal();
	Animal(std::string name);
	Animal(std::string name, int age, bool isMale);
	Animal(const Animal &animal);
	Animal(Animal &&animal);
	~Animal();

	// Akcesory - setters
	void SetName(std::string);
	void SetAge(int);
	void SetImage(char *imageData);

	// Akcesory - getters
	std::string GetName() const;
	int GetAge() const;
	char *GetImage() const;

	// Operatory
	Animal &operator=(const Animal &animal);
	Animal &operator=(Animal &&animal);
	Animal &operator++();
	Animal operator++(int);
	Animal operator+(const Animal &animal);

	// Animal actions
	virtual Action ActionInfo(int index);
	virtual void DoAction();
	virtual void ActionThinking();
	virtual void ActionMoving();
	virtual void ActionSpecial();
	virtual void ActionSleeping();
	virtual void ActionCollision();

	// Pozosta�e metody
	virtual std::string GetInfo();
	virtual void PrintInfo();
	virtual std::string GetType();
};
