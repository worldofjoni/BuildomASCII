// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

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
					openSound();
					Build build(fileManager.getLevel(names[(x - 1) + ((currentPage - 1) * MAX_NAMES_ON_LIST)], LevelType::CUSTOM));
					build.run();
				}

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
				if (x < maxX)
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
			case 27: //ESC
				closeSound();
				return;
				break;
			case 8:
				if (x > 0)
				{
					if (confirm())
					{
						 fileManager.deleteCusLevel(names[(x - 1) + ((currentPage - 1) * MAX_NAMES_ON_LIST)]);
						 initScreen();
						 gotoxy(12, 5);
						 std::cout << "Gel\x94\scht!";
					}
					else
						initScreen(x, currentPage);
				}
				break;
			case 63:
				initScreen();
				break;
			case 64: // F6
				if (x > 0)
				{
					LevelEditor editor(fileManager.getLevel(names[(x - 1) + ((currentPage - 1) * MAX_NAMES_ON_LIST)], LevelType::CUSTOM), names[(x - 1) + ((currentPage - 1) * MAX_NAMES_ON_LIST)]);
					editor.run();
					initScreen(x, currentPage);
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
}




CustomLevelSelect::CustomLevelSelect()
{
	
}

CustomLevelSelect::~CustomLevelSelect()
{
	
}

void CustomLevelSelect::initScreen(int prevX, int prevPage)
{
	nameCount = fileManager.getCustomLvlNames(names);

	maxPage = nameCount / MAX_NAMES_ON_LIST + 1;

	if(nameCount % MAX_NAMES_ON_LIST == 0)
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
		maxPage = 1;
		maxX = 0;

	}
	setBlank();

	std::string title = "EIGENE LEVEL";
	Pos titlePos = { (WIDTH - title.length()) / 2, 3 };
	writeAt(titlePos, title.c_str());

	writeAt({ 4, 5 },( "["+ std::to_string(currentPage) + "/" + std::to_string(maxPage) + "]").c_str());
	Pos start_ = { 10, HEIGHT - 7 };
	Pos page_ = { 11, HEIGHT - 7 };
	writeAt(start_, " [ENTER] Level starten \xb3    [F6] : Level bearbeiten   \xb3 [ESC] : Verlassen");
	start_.y += 2;
	writeAt(start_, "[BACK] : Level l\x94 \bschen \xb3 [TAB] : Dateiexplorer \x94 \bffnen \xb3 [F5] : Liste aktualisieren");
	start_.y += 2;
	start_.x = (WIDTH - 39) / 2;
	writeAt(start_, "[A] Vorherige Seite \xb3 [D] N\x84\chste Seite");

	current.y = start.y + (x * gap);



	writeAt(start, createCustomButton.name.c_str());

	
	for (int i = 1;startNum <= endNum; i++)
	{
		writeAt({ start.x, start.y + gap * i }, names[startNum - 1].c_str());
		startNum++;
	}



	printScreen();

	gotoxy(current.x, current.y);
	std::cout << '>';
}

bool CustomLevelSelect::confirm()
{
	gotoxy(12, 5);
	std::cout << "Wirklich l\x94 \bschen? [ENTER]";
	if (_getch() == 13)
		return true;
	return false;
}
