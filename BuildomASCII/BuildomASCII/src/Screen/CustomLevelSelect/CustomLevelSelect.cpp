#include "pch/pch.h"
#include "CustomLevelSelect.h"


void CustomLevelSelect::run()
{
	std::string names[100];
	int nameCount = fileManager.getCustomLvlNames(names);
	int gap = 2;

	Pos start = { 1, 1 };
	Pos current = { start.x - 1, start.y };

	writeAt(start, createCustomButton.word.c_str());

	for (int i = 1; i <= nameCount; i++)
	{
		writeAt({ start.x, start.y + gap * i }, names[i].c_str());
	}




	fc::hideCursor();
	gotoxy(current.x, current.y);
	std::cout << '>';

	printScreen();


	while (true)
	{
		if (_kbhit())
		{
			input = _getch();

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

				// reinit screen
				printScreen();
				x = 0;
				input = 0;

			}

			switch (input)
			{
			case 'w':
				if (x > 0)
				{
					x--;
				}

				break;
			case 'a':

				break;
			case 's':
				if (x < nameCount)
				{
					x++;
				}
				break;
			case 'd':

				break;
			case 27:
				return;
				break;
			default:
				break;
			}



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
	setBlank();
}

CustomLevelSelect::~CustomLevelSelect()
{
	
}