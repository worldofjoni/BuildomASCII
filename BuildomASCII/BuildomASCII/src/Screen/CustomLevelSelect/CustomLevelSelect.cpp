#include "pch/pch.h"
#include "CustomLevelSelect.h"
#include "Screen/LevelEditor/LevelEditor.h"


void CustomLevelSelect::run()
{
	initScreen();
	
	while (true)
	{
		if (_kbhit())
		{
			input = getCharLow();
			if (input == -32) input = _getch(); // for arrow key
			if (input == 0) input = _getch(); // for F..

			if (input == 32 || input == 13)
			{
				if (x == 0)
				{
					createCustomButton.run();
				}
				else
				{
					Build build(fileManager.getLevel(names[x - 1], LevelType::CUSTOM));
					build.run();
				}

				//reinit screen
				initScreen(x);
				

			}

			switch (input)
			{
			case 'w':
			case 72:
				if (x > 0)
				{
					x--;
				}

				break;
			case 'a':
			case 75:

				break;
			case 's':
			case 80:
				if (x < nameCount)
				{
					x++;
				}
				break;
			case 'd':
			case 77:

				break;
			case 27:
				return;
				break;
			case 63:
				initScreen(x);
				break;
			case 64: // F6
				if (x > 0)
				{
					LevelEditor editor(fileManager.getLevel(names[x - 1], LevelType::CUSTOM), names[x-1]);
					editor.run();
					initScreen(x);
				}
				break;
			case 9:
				fc::openBrowser(fileManager.cNamePath);
				break;
			default:
				break;
			}


			gotoxy(current.x, current.y);
			std::cout << ' ';

			current.y = start.y + (x * gap);
			gotoxy(current.x, current.y);
			std::cout << '>';


		}
	}
	//writeAt(startPos.x, startPos.y, playButton.word.c_str());
}




CustomLevelSelect::CustomLevelSelect()
{
	
}

CustomLevelSelect::~CustomLevelSelect()
{
	
}

void CustomLevelSelect::initScreen(int prevX)
{
	x = prevX;
	setBlank();

	Pos start_ = { 5, HEIGHT - 3 };
	start_ = writeAt(start_, "[F5] : Bildschirm aktualisieren \xb3 [F6] : Level bearbeiten \xb3 [TAB] : Dateiexplorer \x94 \bffnen");

	current.y = start.y + (x * gap);

	nameCount = fileManager.getCustomLvlNames(names);


	writeAt(start, createCustomButton.name.c_str());

	for (int i = 1; i <= nameCount; i++)
	{
		writeAt({ start.x, start.y + gap * i }, names[i - 1].c_str());
	}

	printScreen();

	gotoxy(current.x, current.y);
	std::cout << '>';
}
