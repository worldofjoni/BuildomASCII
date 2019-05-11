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

	writeAt(WIDTH / 2.5, HEIGHT / 2, "Developers: Jonatan Ziegler & Samuel Pasieka");
	


	
	writeAt(exitBut.x - 1, exitBut.y, '>');
	writeAt(exitBut, exitButton.word.c_str());

	printScreen();

	while (true)
	{
		if (_kbhit())
		{
			return;
		}
	}
}


