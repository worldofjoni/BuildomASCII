// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Manual.h"


int Manual::calls = 0;

Manual::Manual()
{
	setBlank();

	if ((calls % 6 == 5)) // easter egg
	{
		writeAt({ 46, 3 }, "NIEMAND");
		writeMultiline({ 5,7 },  content_, WIDTH - 10);
	}
	else
	{
		writeAt({ 46, 3 }, "ANLEITUNG");
		writeMultilineSyms({ 5,7 }, content, WIDTH - 10, elements);
	}
	
	writeAt((Screen::WIDTH - 35) / 2, Screen::HEIGHT - 3, "[ESC], [LEER], [ENTER] : Verlassen");
	calls++;
	printScreen();
}

Manual::~Manual()
{
	for (int i = 0; i < elLen; i++)
	{
		delete elements[i];
		elements[i] = nullptr;
	}
}

void Manual::run()
{
	while (true) if (_kbhit())
	{
		char c = getCharLow();
		if (c == 27 || c == 13 || c == ' ') // Exit
		{
			closeSound();
			return;
		}

	}
	
}
