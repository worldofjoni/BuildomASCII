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
	startPos.x = WIDTH / 2;
	startPos.y = HEIGHT / 2;


	Pos currentPos;
	currentPos.x = startPos.x - 1;
	currentPos.y = startPos.y;



	// Create Buttons and change maxSel accordingly
	writeAt(startPos.x, startPos.y, playButton.name.c_str());
	writeAt(startPos.x, startPos.y + gap, customButton.name.c_str());
	writeAt(startPos.x, startPos.y + gap * 2, manualButton.name.c_str());
	writeAt(startPos.x, startPos.y + gap * 3, creditsButton.name.c_str());
	writeAt(startPos.x, startPos.y + gap * 4, exitButton.name.c_str());
	//writeAt(startPos.x - 4, startPos.y - (gap + 2), title.c_str());
	
	
	

	
	
	
	

	printScreen();


	// Begin main loop
	Button* select = &playButton;
	int curSel = 0;
	int input;

	gotoxy(currentPos.x, currentPos.y);
	std::cout << '>';
	while (true)
	{
		if (_kbhit())
		{
			input = getCharLow();

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

			currentPos.y = startPos.y + (curSel * gap);
			gotoxy(currentPos.x, currentPos.y);
			std::cout << '>';
			
		}

	}

	

}




StartScreen::~StartScreen()
{
}

