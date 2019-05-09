#include "pch/pch.h"
#include "StartScreen.h"

#include "Button/Button.h"
#include <conio.h>

void StartScreen::run() 
{
	setBlank();

	int gap = 2;

	

	// Create Coordinates
	Position startPos;
	startPos.x = 4;
	startPos.y = 4;


	Position currentPos;
	currentPos.x = startPos.x - 1;
	currentPos.y = startPos.y;



	// Create Buttons and change maxSel accordingly
	writeAt(startPos.x, startPos.y, playButton->word.c_str());
	writeAt(startPos.x, startPos.y + gap, exitButton->word.c_str());
	
	
	
	

	
	
	
	

	printScreen();


	// Begin main loop
	Button* select = playButton;
	int curSel = 0;
	int input;

	gotoxy(currentPos.x, currentPos.y);
	std::cout << '>';
	gotoxy(0, 0);
	while (true)
	{
		if (_kbhit())
		{
			input = _getch();

			if (input == 32) {
				if (select->run() == 1) {
					return;
				}
				else
				{
					// reinit screen
					printScreen();
					select = playButton;
					curSel = 0;
				}
			}

			switch (input)
			{
			case 'w':
				if (curSel > 0)
				{
					curSel--;
				}
			
				break;
			case 'a':

				break;
			case 's':
				if (curSel < maxSel -1)
				{
					curSel++;
				}
				break;
			case 'd':

				break;
			default:
				break;
			}

			
			switch (curSel)	// Add options if added more buttons
			{
			case 0:
				select = playButton;
				break;
			case 1:
				select = exitButton;
				break;
			default:
				break;
			}
			
			gotoxy(currentPos.x, currentPos.y);
			std::cout << ' ';

			currentPos.y = startPos.y + (curSel * gap);
			gotoxy(currentPos.x, currentPos.y);
			std::cout << '>';
			gotoxy(0, 0);
			
		}

	}

	

}



StartScreen::StartScreen()
{
}

StartScreen::~StartScreen()
{
	delete playButton;
	delete exitButton;
}

