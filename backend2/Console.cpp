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

void Console::moveAnimal(Animal animal)
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

int Console::GetWidth()
{
	return width;
}

int Console::GetHeight()
{
	return height;
}

/* 
#define COORD_00 \
	COORD { 0, 0 }

Console::~Console()
{
	if (bufferBackground)	delete[] bufferBackground;
	if (bufferPlayground)	delete[] bufferPlayground;
}





void Console::SetSize(short width, short height)
{
	if (bufferBackground) delete[] bufferBackground;
	if (bufferPlayground) delete[] bufferPlayground;

	size = { width, height };
	window_size = { 0,0, width - 1, height - 1 };

	bufferBackground = new CHAR_INFO[width*height];				// Aloocate buffer for console
	bufferPlayground = new CHAR_INFO[width*height];

	//SetConsoleTitle(L"The animals' playground"); IMPOSSIBLE IN MAC					// Set console title
	//SetConsoleScreenBufferSize(hConsole, size);						// Set screen's buffer size
	SetConsoleWindowInfo(hConsole, TRUE, &window_size);				// Set window size

																	// Preparing green empty buffer
	for (short y = 0; y < height; ++y)
		for (short x = 0; x < width; ++x)
		{
			BufferPos(bufferBackground, x, y)->Char = (unsigned char)0;
			BufferPos(bufferBackground, x, y)->Attributes = BACKGROUND_GREEN;
		}
}

CHAR_INFO* Console::BufferPos(CHAR_INFO *buffer, short x, short y)
{
	return &buffer[x + size.X * y];
}

void Console::BufferPrepare()
{
	memcpy(bufferPlayground, bufferBackground, sizeof(CHAR_INFO) * size.X * size.Y);
}

void Console::BufferToScreen()  //OK
{
	for(int i = 0; i < size.Y; i++)
		for(int j = 0; j < size.X; j++)
			addch(bufferPlayground[i*size.Y + j].Char);
	refresh();
	//WriteConsoleOutputA(hConsole, bufferPlayground, size, COORD_00, &window_size);
}

void Console::HideCursor()  //OK
{
	curs_set(0);
}

void Console::GotoXY(short x, short y)
{
	move(x, y);
}

void Console::BufferWrite(const short x, const short y, const std::string info, short attributes)
{
	const char* text = info.c_str();
	int maxCharsToCopy = size.X - x - 1;
	int textLength = strlen(text);
	int charsToCopy = textLength > maxCharsToCopy ? maxCharsToCopy : textLength;

	for (int i = 0; i < charsToCopy; i++)
	{
		CHAR_INFO *charptr = BufferPos(bufferPlayground, x + i, y);
		charptr->Char = text[i];
		charptr->Attributes |= attributes;
	}
}

void Console::BufferFrameAround(const short x, const short y, const short delta, const short color)
{
	for (int ix = x - delta; ix <= x + delta; ix++)
		for (int iy = y - delta; iy <= y + delta; iy++)
		{
			if ((ix > 0) && (ix < size.X ) && (iy > 0) && (iy < size.Y))
			{
				CHAR_INFO *field = &bufferBackground[ix - 1 + size.X * iy];
				field->Attributes = color;
			}
		}
}


bool Console::KeyPressed(int vKey)
{
	SHORT WINAPI state = GetAsyncKeyState(vKey) && 0x8000;
	return state == 1;
}
#pragma endregion */