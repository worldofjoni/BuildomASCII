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
	Position startPos;
	startPos.x = WIDTH / 2;
	startPos.y = HEIGHT / 2;


	Position currentPos;
	currentPos.x = startPos.x - 1;
	currentPos.y = startPos.y;



	// Create Buttons and change maxSel accordingly
	writeAt(startPos.x, startPos.y, playButton.word.c_str());
	writeAt(startPos.x, startPos.y + gap, customButton.word.c_str());
	writeAt(startPos.x, startPos.y + gap * 2, creditsButton.word.c_str());
	writeAt(startPos.x, startPos.y + gap * 3, exitButton.word.c_str());
	//writeAt(startPos.x - 4, startPos.y - (gap + 2), title.c_str());
	
	
	

	
	
	
	

	printScreen();


	// Begin main loop
	Button* select = &playButton;
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

			if (input == 32 || input == 13) {
				if (select->run() == 1) {
					return;
				}
				else
				{
					// reinit screen
					printScreen();
					select = &playButton;
					curSel = 0;
					input = 0;
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
			case 27:
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
				select = &creditsButton;
				break;
			case 3:
				select = &exitButton;
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




StartScreen::~StartScreen()
{
}

