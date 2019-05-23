#include "pch/pch.h"
#include "Manual.h"




Manual::Manual()
{
	setBlank();

	writeAt({ 5, 4 }, (calls == 6) ? "NIEMAND" : "ANLEITUNG");
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
			char c = uts::getCharLow();
			if (c == 27 || c == 13 || c == ' ') return;
		}
	}
}

int Manual::calls = 0;
