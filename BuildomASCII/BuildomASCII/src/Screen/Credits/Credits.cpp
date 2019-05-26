// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Credits.h"


Credits::Credits()
{
	setBlank();

	//gamename
	Pos gameNamePos = { (WIDTH - gameName.length()) / 2, HEIGHT / 4 };

	writeAt(gameNamePos, gameName.c_str());

	//names
	Pos creditPos = { (WIDTH - content.length()) / 2, HEIGHT / 2 };

	writeAt(creditPos, content.c_str());
	
	//music
	writeMultiline({ (WIDTH - 60) / 2, HEIGHT * 3 / 4 }, music, 60);

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


