// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Credits.h"


Credits::Credits()
{
	setBlank();

	//credits:
	char symbols[] = {184};
	writeMultiline({ (WIDTH - contentWidth) / 2, (HEIGHT - contentHeight) / 2 - 4 }, content, contentWidth + 1, symbols);

	std::string keys = "[ESC], [LEER], [ENTER] : Verlassen";
	writeAt({ (WIDTH - (int)keys.length()) / 2, HEIGHT - 3 }, keys.c_str());


	printScreen();
}


Credits::~Credits()
{
}

void Credits::run()
{
	
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


