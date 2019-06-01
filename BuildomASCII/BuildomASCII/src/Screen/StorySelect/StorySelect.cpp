// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

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

			if (input == 32 || input == 13) // Enter or Space
			{
				openSound();
				Build build(fileManager.getLevel(std::to_string(x + 1), LevelType::STORY));
				build.run();

				//reinit screen
				initScreen(x, currentPage);


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
				if (currentPage > 1)
				{
					currentPage--;
					initScreen(0, currentPage);
				}
				break;
			case 's':
			case 80:
				if (x < maxX - 1)
				{
					x++;
				}
				break;
			case 'd':
			case 77:
				if (currentPage < maxPage)
				{
					currentPage++;
					initScreen(0, currentPage);
				}
				break;
			case 27: // ESC
				closeSound();
				return;
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
}




StorySelect::StorySelect()
{
	
}

StorySelect::~StorySelect()
{

}

void StorySelect::initScreen(int prevX, int prevPage)
{
	nameCount = fileManager.getStoryCount();
	maxPage = nameCount / MAX_NAMES_ON_LIST + 1;

	if (nameCount % MAX_NAMES_ON_LIST == 0)
		maxPage = nameCount / MAX_NAMES_ON_LIST;
	currentPage = prevPage;
	x = prevX;

	int startNum = 1 + MAX_NAMES_ON_LIST * (currentPage - 1);
	int endNum = MAX_NAMES_ON_LIST * currentPage;

	if (currentPage == maxPage && nameCount % MAX_NAMES_ON_LIST != 0)
		endNum = (MAX_NAMES_ON_LIST * (currentPage - 1)) + nameCount % MAX_NAMES_ON_LIST;

	maxX = endNum - startNum + 1;

	if (nameCount == 0)
	{
		endNum = 0;
		maxPage = 1;
		maxX = 0;

	}

	// Define screen content

	setBlank();
	std::string title = "LEVELAUSWAHL";
	Pos titlePos = { (WIDTH - title.length()) / 2, 3 };
	writeAt(titlePos, title.c_str());


	Pos start_ = { 30, HEIGHT - 3 };
	start_ = writeAt(start_, "[ENTER] Level starten \xb3 [ESC] : Verlassen");

	current.y = start.y + (x * gap);

	// Write entries to screen
	for (int i = 1; startNum <= endNum; i++)
	{
		writeAt({ start.x, start.y + gap * (i - 1)}, ("Level " + std::to_string(i)).c_str());
		startNum++;
	}

	if(nameCount > MAX_NAMES_ON_LIST)
		writeAt({ 4, 5 }, ("[" + std::to_string(currentPage) + "/" + std::to_string(maxPage) + "]").c_str());

	printScreen();

	gotoxy(current.x, current.y);
	std::cout << '>';
}
