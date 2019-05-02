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
	startPos.x = 1;
	startPos.y = 1;


	Position currentPos;
	currentPos.x = startPos.x;
	currentPos.y = startPos.y;



	// Create Buttons
	placeWord(startPos.x, startPos.y, playButton);
	placeWord(startPos.x, startPos.y + gap, exitButton);
	const int maxSel = 2;

	printScreen();


	// Begin main loop
	Button* select = playButton;
	int curSel = 0;
	char input;
	while (true)
	{
		if (_kbhit())
		{
			input = _getch();

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
				if (curSel < maxSel)
				{
					curSel++;
				}
				break;
			case 'd':

				break;
			default:
				break;
			}
			
			
		}

	}

	

}

StartScreen::~StartScreen()
{
	delete playButton;
	delete exitButton;
}

void StartScreen::placeWord(int px, int py, Button *button) {
	
	
	int x = px;
	for (int i = 0; i < button->wordSize; i++)
	{
		
		content[py][x] = button->word[i];
		x++;
		
		
	}
}