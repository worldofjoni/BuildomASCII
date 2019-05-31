// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Manual.h"




Manual::Manual()
{
	setBlank();

	if ((calls % 6 == 5))
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


	printScreen();
	fc::setCursorPos(0, 0);
	while (true)
	{
		if (_kbhit())
		{
			char c = getCharLow();
			if (c == 27 || c == 13 || c == ' ')
			{
				closeSound();
				return;
			}

		}
	}
}

int Manual::calls = 0;
