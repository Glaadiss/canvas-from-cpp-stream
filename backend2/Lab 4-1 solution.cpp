// Lab 4-1 solution.cpp : Virtual functions; vector of pointers etc
#include "stdafx.h"
#include "Dog.h"
#include "Cat.h"
#include "Rabbit.h"
#include "Playground.h"

int main()
{
	// create and configure playground for animals
	Playground &playground = Playground::GetInstance();
	// create and configure console
	Console &console = Console::GetInstance();
	//console.SetSize(120, 50);

	// create animals
	Dog fafik("Fafik");
	Dog puszek("Puszek");
	Dog borek("Borek");
	Cat pimpek("Pimpek");
	Cat kicius("Kicius");
	Rabbit antek("Antek");
	Rabbit rysio("Rysio");

	// add animals to playground
	playground.AddAnimal(fafik);
	playground.AddAnimal(puszek);
	playground.AddAnimal(borek);
	playground.AddAnimal(pimpek);
	playground.AddAnimal(kicius);
	playground.AddAnimal(antek);
	playground.AddAnimal(rysio);

	// simulation main loop
	while (true)
	{
	};
	//playground.Simulate();

	return 0;
}