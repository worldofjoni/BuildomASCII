#include "pch/pch.h"
#include "Credits.h"


Credits::Credits()
{
}


Credits::~Credits()
{
}

void Credits::run()
{
	setBlank();

	Pos exitBut;
	exitBut.x = WIDTH / 2;
	exitBut.y = HEIGHT - 2;

	writeAt(WIDTH / 2.5, HEIGHT / 2, content.c_str());
	


	
	writeAt(exitBut.x - 1, exitBut.y, '>');
	writeAt(exitBut, exitButton.word.c_str());

	printScreen();

	while (true)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == 27 || c == 13 || c == ' ') return;
		}
	}
}


