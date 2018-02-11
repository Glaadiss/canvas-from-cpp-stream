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
	void moveAnimal(Animal animal);

	int GetWidth();
	int GetHeight();
};

/* // START OF MAC OS HACKS
struct COORD
{
	int X;
	int Y;
};

struct SMALL_RECT
{
	int Left;
	int Top;
	int Right;
	int Bottom;
};

struct CHAR_INFO
{
	char Char;
	short Attributes;
};
// END OF MAC OS HACKS

class Console
{
  public:
	// Win32 console stuff
	SMALL_RECT window_size;
	COORD size;

	CHAR_INFO *bufferBackground = nullptr;
	CHAR_INFO *bufferPlayground = nullptr;

	Console();
	~Console();
	Console(const Console &) = delete;
	Console &operator=(Console &) = delete;




	void SetSize(short width, short height);

	// Win32 console stuff
	CHAR_INFO *BufferPos(CHAR_INFO *buffer, short x, short y);

	void BufferPrepare();
	void BufferToScreen();
	void BufferWrite(const short x, const short y, const std::string info, const short color);
	void BufferFrameAround(const short x, const short y, const short delta, const short color);

	void HideCursor();
	bool KeyPressed(int vKey);
	void GotoXY(short x, short y);
};
 */