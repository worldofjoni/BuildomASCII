#include "pch/pch.h"
#include "Build.h"

#include "LevelElement/LevelElement.h"



// prints content at x|y whit color on Screen
template <typename T>
void Build::printOnLevel(T content, int x, int y, fc::Color color, fc::Color backgroundColor)
{
	fc::setCursorPos(x + 1, y + 1); // +1 is offset for Frame
	fc::setBackgroundColor(backgroundColor);
	fc::setTextColor(color);
	std::cout << content;
	fc::setCursorPos(0, 0);
}


// Constructor with content init
Build::Build(Level level)
	:level(level)
{
	setBlank();
	// init frame
	for (int y = 0; y < HEIGHT; y++)
	{
		content[0][y].content = ' ';
		content[0][y].textColor = frameTextColor;
		content[0][y].backgroundColor = frameColor;

		content[WIDTH-1][y].content = ' ';
		content[WIDTH-1][y].textColor = frameTextColor;
		content[WIDTH-1][y].backgroundColor = frameColor;
	}

	for (int x = 0; x < WIDTH; x++)
	{
		content[x][0].content = ' ';
		content[x][0].textColor = frameTextColor;
		content[x][0].backgroundColor = frameColor;

		for (int y = HEIGHT - 10; y < HEIGHT; y++)
		{
			content[x][y].content = ' ';
			content[x][y].textColor = frameTextColor;
			content[x][y].backgroundColor = frameColor;
		}
	}

	// initializes the content to the element of the level at each spot
	for (int x = 0; x < this->level.WIDTH; x++) 
	{
		for (int y = 0; y < this->level.HEIGHT; y++)
		{
			content[x+1][y+1].content = this->level.map[x][y]->symbol;
			content[x+1][y+1].textColor = this->level.map[x][y]->color;
			content[x+1][y+1].backgroundColor = this->defaultBackgroundColor;
		}
	}

	
	// init for menu bar
	bool firstIsPlaced = false;
	Pos pos = { 3, Screen::HEIGHT - 7 };

	char symbols[LevelElement::countOfElements] = { ' ', 219, '/', '\\', 29 }; // has to be manualy updated ###############################
	char keybind[LevelElement::countOfElements][10] = { "BACK", "SPACE", "1", "2", "3" }; // same ##########################################

	for (int i = 1; i < LevelElement::countOfElements; i++) // 1 because empty field is NOT displayed
	{

		// when no blocks of this kind are allowed
		if (level.maxElements[i] == 0)
			continue;

		// if this is not the first block: Prevent '|' on border
		if (firstIsPlaced)
		{
			menuPos = writeAt(menuPos, "  ");
			content[menuPos.x][menuPos.y].textColor = RED;
			menuPos = writeAt(menuPos, 179);
			menuPos = writeAt(menuPos, "  ");
		}

		content[menuPos.x][menuPos.y].textColor = GREEN;
		menuPos = writeAt(menuPos, symbols[i]);
		menuPos = writeAt(menuPos, " [");
		menuPos = writeAt(menuPos, keybind[i]);
		menuPos = writeAt(menuPos, "] : ");
		countPos[i] = menuPos; // save position of number for later updates

		// checks for infinite blocks
		if (level.maxElements[i] == -1)
			menuPos = writeAt(menuPos, " - ");
		else
			menuPos = writeAt(menuPos, level.maxElements[i], 3);

		firstIsPlaced = true;

	}

	//Delete & Quit
	pos = { Screen::WIDTH - 55, Screen::HEIGHT - 3 };
	pos = writeAt(pos, "[BACK] : Delete  ");
	content[pos.x][pos.y].textColor = RED;
	pos = writeAt(pos, 179);
	pos = writeAt(pos, "  [ESC] : Quit ");
	content[pos.x][pos.y].textColor = RED;
	pos = writeAt(pos, 179);
	pos = writeAt(pos, "  [ENTER] : Start ");
}




void Build::run()
{
	

	
	LevelElement *setElement = nullptr; // Elemet player can set on screen
	Direction dir = NONE;
	Cursor cursor(&level);
	printScreen();


	
	while (true)
	{
		if (_kbhit())
		{
			if (keyHandeling(setElement, dir))
				return;


			// if a new Element should be set...
			if (setElement != nullptr)
			{
				placeOnLevelAt(setElement, cursor.x, cursor.y);
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

bool Build::runLevel(Level level)
{
	currentPos = { level.start.x, level.start.y };
	playerGameOver = false;
	playerDirection = RIGHT;

	int repeats;

	while (!playerGameOver)
	{
		repeats = 0;


		if (playerDirection == RIGHT) { currentPos.x++; }
		else if (playerDirection == LEFT) { currentPos.x--; }

		level.map[currentPos.x][currentPos.y]->steppedIn(build);

		do
		{

			if (currentPos.x + 1 >= level.WIDTH || currentPos.y + 1 >= level.HEIGHT || currentPos.x <= 0 || currentPos.y <= 0)
			{
				playerGameOver = true;
				repeats = fallSpeed;
				continue;
			}


			if (currentPos.x == level.end.x && currentPos.y == level.end.y)
			{

				return true;
			}
			if (level.map[currentPos.x][currentPos.y + 1]->fallable)
			{
				currentPos.y++;
				level.map[currentPos.x][currentPos.y]->steppedIn(build);
			}
			
			repeats++;



		} while (repeats < fallSpeed); 


		if (currentPos.x + 1 >= level.WIDTH|| currentPos.y + 1 >= level.HEIGHT || currentPos.x <= 0 || currentPos.y <= 0)
		{
			playerGameOver = true;
			continue;
		}

		level.map[currentPos.x][currentPos.y + 1]->steppedOn(build);

		
		
		printOnLevel(playerChar, currentPos.x, currentPos.y, RED_LIGHT);

		fc::waitMs(100);


		if (_kbhit())
		{
			if (_getch() == 27)
			{
				playerGameOver = true;
			}
		}

		if (currentPos.x == level.end.x && currentPos.y == level.end.y)
		{
			
			return true; 
		}
		

		printOnLevel(level.map[currentPos.x][currentPos.y]->symbol, currentPos.x, currentPos.y, level.map[currentPos.x][currentPos.y]->color);
		

		
	}
	printOnLevel(playerDeadChar, currentPos.x, currentPos.y, BLUE_LIGHT);
	fc::waitMs(500);
	printOnLevel(level.map[currentPos.x][currentPos.y]->symbol, currentPos.x, currentPos.y, level.map[currentPos.x][currentPos.y]->color);
	return false;
}

bool Build::keyHandeling(LevelElement*& setElement, Direction& dir)
{

	int key = _getch();
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
		setElement = new Solid(true);
		break;
	case 8://backspace
		setElement = new Empty(true);
		break;
	case '1':
		setElement = new SlopeUp(true);
		break;
	case '2':
		setElement = new SlopeDown(true);
		break;
	case '3':
		setElement = new ChangeDir(true);
		break;


	case 27: // ESC
		return true;
		break;

	default:
		dir = NONE;
		break;
	}

	return false;
}

// checks wether a block could be placed and does so
void Build::placeOnLevelAt(LevelElement*& element, int x, int y)
{
	// Handeling limited Blocks
	int id = element->id;

	if ((level.setElements[id] < level.maxElements[id] || level.maxElements[id] == -1) && level.map[x][y]->deletable)
	{
		level.setElements[level.map[x][y]->id]--; // decrement deleted

		level.setElements[id]++; // increment new

		// colors for number replacement
		fc::setBackgroundColor(frameColor);
		fc::setTextColor(frameTextColor);

		//replace number in display : old Element (unless max is empty or inf. or 0)
		if (level.map[x][y]->id != 0 && level.maxElements[level.map[x][y]->id] != -1 && level.maxElements[level.map[x][y]->id] != 0)
		{
			
			fc::setCursorPos(countPos[level.map[x][y]->id].x, countPos[level.map[x][y]->id].y);
			std::cout << std::setw(3) << (level.maxElements[level.map[x][y]->id] - level.setElements[level.map[x][y]->id]);
		}

		// new Element display update (unless max is empty or inf. or 0)
		if (id != 0 && level.maxElements[id] != -1 && level.maxElements[level.map[x][y]->id] != 0)
		{
			fc::setCursorPos(countPos[id].x, countPos[id].y);
			std::cout << std::setw(3) << (level.maxElements[id] - level.setElements[id]);
		}

		level.placeAt(element, x, y);
		element = nullptr;

	}
	else
	{
		delete element;
		element = nullptr;
	}
}



