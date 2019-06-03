// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Credits.h"


Credits::Credits()
{
	setBlank();

	// print Credits
	char symbols[] = {184}; // (c)
	writeMultiline({ (WIDTH - contentWidth) / 2, (HEIGHT - contentHeight) / 2 - 4 }, content, contentWidth + 1, symbols);

	// Available commands
	std::string keys = "[ESC], [LEER], [ENTER] : Verlassen";
	writeAt({ (WIDTH - (int)keys.length()) / 2, HEIGHT - 3 }, keys.c_str());
	keys = "[TAB] : Github Link \x94 \bffnen";
	writeAt({ (WIDTH - (int)keys.length()) / 2, HEIGHT - 5 }, keys.c_str());

	printScreen();
}

void Credits::run()
{
	while (true) if (_kbhit())
	{
		char c = getCharLow();
		if (c == 27 || c == 13 || c == ' ') // Exit
		{
			closeSound();
			return;
		}
		else if (c == 9) // TAB
			fc::openBrowser("https://github.com/worldofjoni/BuildomASCII");
	}
	
}


