#include "pch/pch.h"
#include "StorySelect.h"

void StorySelect::run()
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
				Build build(fileManager.getLevel(std::to_string(x + 1), LevelType::STORY));
				build.run();

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
				if (x < nameCount - 1)
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
				initScreen();
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




StorySelect::StorySelect()
{

}

StorySelect::~StorySelect()
{

}

void StorySelect::initScreen(int prevX)
{
	x = prevX;
	setBlank();

	Pos start_ = { 5, HEIGHT - 3 };
	start_ = writeAt(start_, "[F5] : Bildschirm aktualisieren");

	current.y = start.y + (x * gap);

	nameCount = fileManager.getStoryCount();
;

	for (int i = 1; i <= nameCount; i++)
	{
		writeAt({ start.x, start.y + gap * (i - 1)}, ("Level " + std::to_string(i)).c_str());
	}

	printScreen();

	gotoxy(current.x, current.y);
	std::cout << '>';
}
