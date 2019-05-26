// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Manual.h"




Manual::Manual()
{
	setBlank();

	writeAt({ 46, 3 }, (calls == 6) ? "NIEMAND" : "ANLEITUNG");
	writeMultiline({ 5,7 }, (calls == 6) ? content_ : content, WIDTH - 10);


	writeAt((Screen::WIDTH - 35) / 2, Screen::HEIGHT - 3, "[ESC], [LEER], [ENTER] : Verlassen");
	calls++;
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
