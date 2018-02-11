#pragma once
#include "ncurses.h"
#include <string>
#include "Animal.h"
#include "json.hh"

class Console
{
  public:
	int width = 1000;
	int height = 800;

	Console();
	~Console();

	static Console &GetInstance();

	void createAnimal(Animal &animal);
	void moveAnimal(Animal &animal);
	void specialAction(Animal &animal);
	void animalSleeping(Animal &animal);
	void animalThinking(Animal &animal);

	int GetWidth();
	int GetHeight();
};