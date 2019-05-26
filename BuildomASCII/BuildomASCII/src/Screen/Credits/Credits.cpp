#include "pch/pch.h"
#include "Credits.h"


Credits::Credits()
{
	setBlank();

	Pos exitBut;
	exitBut.x = WIDTH / 2;
	exitBut.y = HEIGHT - 2;
	Pos creditPos = { (WIDTH - content.length()) / 2, HEIGHT / 4 };

	writeAt(creditPos, content.c_str());
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


