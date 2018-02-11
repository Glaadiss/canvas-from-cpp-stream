#pragma once
#include <vector>
#include "Animal.h"
#include "Console.h"

class Playground // as singleton
{
  private:
	// Object containers - now one for all
	std::vector<Animal *> animals;

  public:
	Playground();
	~Playground();
	Playground(const Playground &) = delete;
	Playground &operator=(Playground &) = delete;

	static Playground &GetInstance();

	void AddAnimal(Animal &animal);
	void AnimalsDoAction();
	Animal &AnimalCollidesWith(Animal &animal);

	void Simulate();
};
