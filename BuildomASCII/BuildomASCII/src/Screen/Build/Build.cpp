#include "pch/pch.h"
#include "Build.h"

#include "LevelElement/LevelElement.h"
#include "Cursor/Cursor.h"




template <typename T>
void Build::printOnLevel(T content, int x, int y, fc::Color color, fc::Color backgroundColor)
{
	fc::setCursorPos(x + 1, y + 1); // +1 is offset for Frame
	fc::setBackgroundColor(backgroundColor);
	fc::setTextColor(color);
	std::cout << content;
	fc::setCursorPos(0, 0);
}



Build::Build(Level level)
	:level(level)
{
	// init frame
	for (int y = 0; y < HEIGHT; y++)
	{
		content[0][y].content = ' ';
		content[0][y].textColor = defaultTextColor;
		content[0][y].backgroundColor = frameColor;

		content[WIDTH-1][y].content = ' ';
		content[WIDTH-1][y].textColor = defaultTextColor;
		content[WIDTH-1][y].backgroundColor = frameColor;
	}

	for (int x = 0; x < WIDTH; x++)
	{
		content[x][0].content = ' ';
		content[x][0].textColor = defaultTextColor;
		content[x][0].backgroundColor = frameColor;

		for (int y = HEIGHT - 10; y < HEIGHT; y++)
		{
			content[x][y].content = ' ';
			content[x][y].textColor = defaultTextColor;
			content[x][y].backgroundColor = frameColor;
		}
	}

	// initializes the content to he symbols of the level at each spot
	for (int x = 0; x < this->level.WIDTH; x++) 
	{
		for (int y = 0; y < this->level.HEIGHT; y++)
		{
			content[x+1][y+1].content = this->level.map[x][y]->symbol;
			content[x+1][y+1].textColor = this->level.map[x][y]->color;
			content[x+1][y+1].backgroundColor = this->defaultBackgroundColor;
		}
	}
	
}




void Build::run()
{
	

	int key = ' ';
	LevelElement *setElement = nullptr; // Elemet player can set on screen
	Direction dir = NONE;
	Cursor cursor(&level);
	printScreen();

	
	while (true)
	{
		if (_kbhit())
		{
			key = _getch();
			switch (key)
			{
			case 'w':
				dir = UP;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case ' ':
				setElement = new Solid;
				break;
			case 8://backspace
				setElement = new Empty;
				break;
			case '1':
				setElement = new SlopeUp;
				break;
			case '2':
				setElement = new SlopeDown;
				break;
				

			default:
				dir = NONE;
				break;
			}

			// if a new Element schould be set...
			if (setElement != nullptr)
			{
				level.addAt(setElement, cursor.x, cursor.y);
				
			}

			// deleting old
			printOnLevel(level.map[cursor.x][cursor.y]->symbol, cursor.x, cursor.y, level.map[cursor.x][cursor.y]->color);

			cursor.move(dir);

			// printing new
			printOnLevel(cursor.symbol, cursor.x, cursor.y, cursor.color);
			
			

		}
		else
		{
			// only blinking when not moving


			// Prints cursor or not for blinking
			printOnLevel((cursor.isVisable ? cursor.symbol : level.map[cursor.x][cursor.y]->symbol), cursor.x, cursor.y, (cursor.isVisable ? cursor.color : level.map[cursor.x][cursor.y]->color));






		}

		dir = NONE;

		

		

		fc::waitMsWithInterupt(500, []() { return (bool)_kbhit(); }); // waits 500ms

		cursor.isVisable = !cursor.isVisable;

	}


	




}
