// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "WinScreen.h"


WinScreen::WinScreen(Build* old)
{
	Pos size = {WIDTH /2, HEIGHT / 2 + 10}; // size of screen;

	// set empty
	for (int x = (WIDTH - size.x) / 2; x < (WIDTH + size.x) / 2; x++)
	{
		for (int y = (HEIGHT - size.y) / 2; y < (HEIGHT + size.y) / 2; y++)
		{
			fc::setCursorPos(x, y);
			std::cout << fc::backColor(backgroundColor) << fc::color(textColor) << ' ';
			
		}
	}
	// frame
	for (int x = (WIDTH - size.x) / 2; x < (WIDTH + size.x) / 2; x++)
	{
		fc::setCursorPos(x, (HEIGHT - size.y) / 2);
		std::cout << fc::backColor(frameColor) << fc::color(textColor) << ' ';

		fc::setCursorPos(x, (HEIGHT + size.y) / 2 - 1);
		std::cout << fc::backColor(frameColor) << fc::color(textColor) << ' ';
	}
	for (int y = (HEIGHT - size.y) / 2; y < (HEIGHT + size.y) / 2; y++)
	{
		fc::setCursorPos((WIDTH - size.x) / 2, y);
		std::cout << fc::backColor(frameColor) << fc::color(textColor) << ' ';

		fc::setCursorPos((WIDTH + size.x) / 2 - 1, y);
		std::cout << fc::backColor(frameColor) << fc::color(textColor) << ' ';
	}

	// logo
	Pos logoPos = { (WIDTH - 27) / 2, (HEIGHT - size.y) / 2 + 2 };

	printMultiline(logoPos, logo, 50, logoColor ,backgroundColor);

	// stars
	Pos starPos = { (WIDTH - size.x) / 2 + 9, (HEIGHT - size.y) / 2 + 10 };
	for (int i = 0; i < Build::maxStars; i++)
	{
		printMultiline(starPos, star, 20, (i < old->stars) ? YELLOW_LIGHT : backgroundColor, backgroundColor);
		starPos.x += 15;

	}

	// time took

	Pos timePos = { (WIDTH - size.x) / 2 + 12, (HEIGHT - size.y) / 2 + 15 };
	fc::setBackgroundColor(backgroundColor);
	fc::setTextColor(textColor);
	fc::setCursorPos(timePos.x, timePos.y);
	int took = std::chrono::duration_cast<std::chrono::milliseconds>((old->t2 - old->t1)).count();
	std::cout << "Dauer: " << took /1000 << "," << took %1000 << " Sekunden";

	// Block stats
	Pos statsPos = { (WIDTH - size.x) / 2 + 12, (HEIGHT - size.y) / 2 + 17 };
	fc::setBackgroundColor(backgroundColor);
	fc::setTextColor(textColor);
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		if (old->level.setElements[i] > 0)
		{
			fc::setCursorPos(statsPos.x, statsPos.y);
			std::cout << fc::color(old->elements[i]->getColor()) << old->elements[i]->symbol << fc::color(textColor) << " : " << std::setw(3) << old->level.setElements[i] << (old->level.setElements[i]==1 ? " Block " : " Bl\x94 \bcke") <<" plaziert";
			statsPos.y++;
		}
	}
	
	// button press hint

	Pos hintPos = { (WIDTH - size.x) / 2 + 7, (HEIGHT + size.y) / 2 - 3 };
	fc::setCursorPos(hintPos.x, hintPos.y);
	std::cout << "[ESC], [LEER], [ENTER] : Verlassen";

}


WinScreen::~WinScreen()
{
}

void WinScreen::run()
{
	while (1)
	{
		if (_kbhit())
		{
			int c = _getch();
			if (c == 27 || c == 13 || c == ' ')
			{
				closeSound();
				return;
			}
		}
	}
}


