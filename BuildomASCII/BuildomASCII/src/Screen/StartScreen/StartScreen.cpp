// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "StartScreen.h"

#include "Button/Button.h"


StartScreen::StartScreen()
{
	setBlank();
	Pos logoStart = { (Screen::WIDTH - LOGO_WIDTH) / 2, 5 };
	for (int y = 0; y < LOGO_HEIGHT; y++)
	{
		for (int x = 0; x < LOGO_WIDTH; x++)
		{
			writeAt({ x + logoStart.x, y + logoStart.y }, logo[y][x]);
			content[x + logoStart.x][y + logoStart.y].textColor = YELLOW_LIGHT;
		}
	}
	
}




void StartScreen::run()
{
	

	int gap = 3;

	//std::string title = "Buildom ASCII";

	// Create Coordinates
	Pos startPos;
	startPos.x = (Screen::WIDTH - LOGO_WIDTH) / 2 + 1;
	startPos.y = HEIGHT / 2 - 3;


	Pos currentPos;
	currentPos.x = startPos.x - 1;
	currentPos.y = startPos.y;



	// Create Buttons and change maxSel accordingly
	writeAt((WIDTH - playButton.name.length()) / 2, startPos.y, playButton.name.c_str());
	writeAt((WIDTH - customButton.name.length()) / 2, startPos.y + gap, customButton.name.c_str());
	writeAt((WIDTH - manualButton.name.length()) / 2, startPos.y + gap * 2, manualButton.name.c_str());
	writeAt((WIDTH - creditsButton.name.length()) / 2, startPos.y + gap * 3, creditsButton.name.c_str());
	writeAt((WIDTH - exitButton.name.length()) / 2, startPos.y + gap * 4, exitButton.name.c_str());
	//writeAt(startPos.x - 4, startPos.y - (gap + 2), title.c_str());
	
	
	

	
	
	
	

	printScreen();


	// Begin main loop
	Button* select = &playButton;
	int curSel = 0;
	int input;

	currentPos.x = (WIDTH - select->name.length()) / 2 - 1;

	gotoxy(currentPos.x, currentPos.y);
	std::cout << '>';
	while (true)
	{
		if (_kbhit())
		{
			input = getCharLow();
			if (input == -32) input = _getch();

			if (input == 32 || input == 13) {
				if (select->run() == 1) {
					return;
				}
				else
				{
					// reinit screen
					printScreen();
					input = 0;
					gotoxy(currentPos.x, currentPos.y);
					std::cout << '>';
				}
			}

			switch (input)
			{
			case 'w':
			case 72:
				if (curSel > 0)
				{
					curSel--;
				}
			
				break;
			case 'a':
			case 75:

				break;
			case 's':
			case 80:
				if (curSel < maxSel -1)
				{
					curSel++;
				}
				break;
			case 'd':
			case 77:

				break;
			case 27: // ESC
				exitButton.run();
				return;
				break;
			default:
				break;
			}

			
			switch (curSel)	// Add options if added more buttons
			{
			case 0:
				select = &playButton;
				break;
			case 1:
				select = &customButton;
				break;
			case 2:
				select = &manualButton;
				break;
			case 3:
				select = &creditsButton;
				break;
			case 4:
				select = &exitButton;
				break;
			default:
				break;
			}
			
			gotoxy(currentPos.x, currentPos.y);
			std::cout << ' ';

			currentPos.x = (WIDTH - select->name.length()) / 2 - 1;
			currentPos.y = startPos.y + (curSel * gap);
			gotoxy(currentPos.x, currentPos.y);
			std::cout << '>';
			
		}

	}

	

}




StartScreen::~StartScreen()
{
}

