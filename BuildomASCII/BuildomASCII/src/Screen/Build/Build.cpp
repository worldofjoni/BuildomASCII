#include "pch/pch.h"
#include "Build.h"

#include "LevelElement/LevelElement.h"



// prints content at x|y whit color on Screen
template <typename T>
void Build::printOnLevel(T content, Pos pos, fc::Color color, fc::Color backgroundColor)
{
	fc::setCursorPos(pos.x + 1, pos.y + 1); // +1 is offset for Frame
	fc::setBackgroundColor(backgroundColor);
	fc::setTextColor(color);
	std::cout << content;
	fc::setCursorPos(0, 0);
}



// Constructor with content init
Build::Build(Level level, bool asEditor)
	:level(level), isEditor(asEditor)
{

	if (this->level.start.x == INVALID) this->level.setStartEnd({ 5,5 }, { level.WIDTH - 6, level.HEIGHT - 6 });

	setBlank();
	// init frame
	for (int y = 0; y < HEIGHT; y++)
	{
		content[0][y].content = ' ';
		content[0][y].textColor = frameTextColor;
		content[0][y].backgroundColor = frameColor;

		content[WIDTH - 1][y].content = ' ';
		content[WIDTH - 1][y].textColor = frameTextColor;
		content[WIDTH - 1][y].backgroundColor = frameColor;
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
			content[x + 1][y + 1].content = this->level.at({ x, y })->symbol;
			content[x + 1][y + 1].textColor = this->level.at({ x, y })->color;
			content[x + 1][y + 1].backgroundColor = this->defaultBackgroundColor;
		}
	}


	// init for menu bar
	bool firstIsPlaced = false;
	Pos menuPos = { 3, Screen::HEIGHT - 7 };



	for (int i = 1; i < LevelElement::countOfElements; i++) // 1 because empty field is NOT displayed
	{

		// when no blocks of this kind are allowed
		if (level.maxElements[i] == 0)
			continue;

		// if this is not the first block: Prevent '|' on border
		if (firstIsPlaced)
		{
			menuPos = writeAt(menuPos, "  ");
			content[menuPos.x][menuPos.y].textColor = menuBarLineColor;
			menuPos = writeAt(menuPos, 179);
			menuPos = writeAt(menuPos, "  ");
		}

		content[menuPos.x][menuPos.y].textColor = elements[i]->color;
		content[menuPos.x][menuPos.y].backgroundColor = WHITE;
		menuPos = writeAt(menuPos, elements[i]->symbol);
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
	menuPos = { Screen::WIDTH - 65, Screen::HEIGHT - 3 };
	menuPos = writeAt(menuPos, "  [");
	menuPos = writeAt(menuPos, keybind[0]);
	menuPos = writeAt(menuPos, "] : L");
	menuPos = writeAt(menuPos, 148);
	menuPos = writeAt(menuPos, "schen ");
	content[menuPos.x][menuPos.y].textColor = menuBarLineColor;
	menuPos = writeAt(menuPos, 179);
	menuPos = writeAt(menuPos, "  [ESC] : Verlassen ");
	content[menuPos.x][menuPos.y].textColor = menuBarLineColor;
	menuPos = writeAt(menuPos, 179);
	menuPos = writeAt(menuPos, isEditor ? " [ENTER] : Speichern  " : " [ENTER] : Starten    ");

	//display start and end key ( if editor)
	if (isEditor)
	{
		menuPos = { 5, Screen::HEIGHT - 3 };
		menuPos = writeAt(menuPos, "[,] : Start ");
		content[menuPos.x][menuPos.y].textColor = menuBarLineColor;
		menuPos = writeAt(menuPos, 179);
		menuPos = writeAt(menuPos, " [.] : Ziel ");
	}

	printScreen();

}


void Build::run()
{
	LevelElement *setElement = nullptr; // Elemet player can set on screen
	Direction dir = NONE;
	Cursor cursor(&level);
	bool enteredRun = false;

	
	while (true) // Build loop
	{
		if (_kbhit()) // when key gets pressed
		{
			if (keyHandeling(setElement, dir, cursor)) return; // leaves editor when e.g. ESC hit or run successfully

			// if there is a new element...
			if (setElement != nullptr) placeOnLevelAt(setElement, cursor.pos); // place element in level object

			// overprint old element
			printOnLevel(level.at(cursor.pos)->symbol, cursor.pos, level.at(cursor.pos)->color);

			cursor.move(dir);

			// print cursor 
			printOnLevel(cursor.symbol, cursor.pos, cursor.color);
		}
		else // cursor blinks only when not moveing
		{
			if (cursor.isVisable)
			{	// print cursor
				printOnLevel(cursor.symbol, cursor.pos, cursor.color);
			}
			else
			{	// print current element
				printOnLevel(level.at(cursor.pos)->symbol, cursor.pos, level.at(cursor.pos)->color);
			}

			
		}
		dir = NONE;


		fc::waitMsWithInterupt(500, []() { return (bool)_kbhit(); }); // waits 500ms ore until key is pressed

		cursor.isVisable = !cursor.isVisable; // alternate cursor visibility
	}
}

bool Build::keyHandeling(LevelElement*& setElement, Direction& dir, Cursor cursor)
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
	case Solid::ownKey:
		setElement = new Solid(true);
		break;
	case Empty::ownKey://backspace
		setElement = new Empty(true);
		break;
	case SlopeUp::ownKey:
		setElement = new SlopeUp(true);
		break;
	case SlopeDown::ownKey:
		setElement = new SlopeDown(true);
		break;
	case ChangeDir::ownKey:
		setElement = new ChangeDir(true);
		break;
	case Spike::ownKey:
		setElement = new Spike(true);
		break;
	case 13: // Space
		if (isEditor) return true;
		
		printOnLevel(level.at(cursor.pos)->symbol, cursor.pos, level.at(cursor.pos)->color);

		if (runLevel()) return true;
		break;
		


	case 27: // ESC
		if (isEditor) cancelEdit = true;
		return true;
		break;

	default:
		dir = NONE;
		break;
	}
	
	if (isEditor && level.at(cursor.pos)->deletable)
	{
		switch (key)
		{
		case ',': // set Start
			//reset old Start
			level.at(level.start)->deletable = true;
			level.at(level.start)->symbol = Empty::ownSym;
			level.at(level.start)->color = Screen::defaultTextColor;
			printOnLevel(level.at(level.start)->symbol, level.start, Screen::defaultTextColor);
			
			// set new ones
			setElement = new Empty(false);
			setElement->symbol = Build::startChar;
			setElement->color = Build::startColor;

			// update start
			level.start = cursor.pos;
			break;
		case '.': // set End
			//reset old end
			level.at(level.end)->deletable = true;
			level.at(level.end)->symbol = Empty::ownSym;
			level.at(level.end)->color = Screen::defaultTextColor;
			printOnLevel(level.at(level.end)->symbol, level.end, Screen::defaultTextColor);
			
			// set new ones
			setElement = new Empty(false);
			setElement->symbol = Build::endChar;
			setElement->color = Build::endColor;

			// update end
			level.end = cursor.pos;
			break;
		default:
			break;
		}
	}

	return false;
}


// Runs the Level after build-mode
bool Build::runLevel()
{
	currentPos = { level.start.x, level.start.y };
	playerGameOver = false;
	playerDirection = RIGHT;
	displayPlayer();

	int repeats;

	while (!playerGameOver)
	{
		repeats = 0;

		movePlayer(playerDirection, 0);

		

		do
		{
			// Check if Player hits border or has already lost
			if ((currentPos.x + 1 >= level.WIDTH) || (currentPos.y + 1 >= level.HEIGHT) || (currentPos.x <= 0) || (currentPos.y <= 0) || (playerGameOver))
			{
				playerGameOver = true;
				repeats = fallSpeed;
				continue;
			}

			// Win
			if (currentPos.x == level.end.x && currentPos.y == level.end.y)
			{

				return true;
			}

			// Falling
			if (level.at(currentPos.below())->fallable)
			{
				movePlayer(0, 1);
			}
			
			repeats++;



		} while (repeats < fallSpeed); // Check after every falling for fallSpeed-reapeats

		// Check if Player hits border or has already lost
		if ((currentPos.x + 1 >= level.WIDTH) || (currentPos.y + 1 >= level.HEIGHT) || (currentPos.x <= 0) || (currentPos.y <= 0))
		{
			playerGameOver = true;
			continue;
		}


		
		
		displayPlayer();

		
		if (_kbhit())
		{
			// Getting out of Run-Mode
			if (_getch() == 27) // Escape
			{
				playerGameOver = true;
			}
		}


		// Win
		if (currentPos.x == level.end.x && currentPos.y == level.end.y)
		{
			
			return true; 
		}
		

		
		

		
	}

	// Display dead Player
	printOnLevel(playerDeadChar, currentPos, BLUE_LIGHT);
	fc::waitMs(movespeed * 5);
	printOnLevel(level.at(currentPos)->symbol, currentPos, level.at(currentPos)->color);
	return false;
}

// checks wether a block could be placed and does so
void Build::placeOnLevelAt(LevelElement*& element, Pos pos)
{
	// Handeling limited Blocks
	int id = element->id;
	int x = pos.x;
	int y = pos.y;

	if ((level.setElements[id] < level.maxElements[id] || level.maxElements[id] == -1) && level.at({ x, y })->deletable) // when allowed to place
	{
		level.setElements[level.at({ x, y })->id]--; // decrement deleted

		level.setElements[id]++; // increment new

		// colors for number replacement
		fc::setBackgroundColor(frameColor);
		fc::setTextColor(frameTextColor);

		//replace number in display : old Element (unless max is empty or inf. or 0)
		if (level.at({ x, y })->id != 0 && level.maxElements[level.at({ x, y })->id] != -1 && level.maxElements[level.at({ x, y })->id] != 0)
		{
			
			fc::setCursorPos(countPos[level.at({ x, y })->id].x, countPos[level.at({ x, y })->id].y);
			std::cout << std::setw(3) << (level.maxElements[level.at({ x, y })->id] - level.setElements[level.at({ x, y })->id]);
		}

		// new Element display update (unless max is empty or inf. or 0)
		if (id != 0 && level.maxElements[id] != -1 && level.maxElements[level.at({ x, y })->id] != 0)
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

Build::~Build()
{
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		delete elements[i];
		elements[i] = nullptr;
	}
	
}


// Moves the Player and triggers new Events
void Build::movePlayer(int xOffset, int yOffset)
{
	previousPos = currentPos;
	previousElementID = level.at(currentPos)->id;
	previousLowerElementID = level.at(currentPos.below())->id;
	currentPos.x += xOffset;
	currentPos.y += yOffset;
	if (currentPos.y + 1 < level.HEIGHT)
	{
		if (level.at(currentPos)->id == 2 || level.at(currentPos)->id == 3)
		{
			level.at(currentPos)->steppedIn(build);
		}
		level.at(currentPos.below())->steppedOn(build);
	}
	while (level.at(currentPos)->id != previousElementID )
	{
		level.at(currentPos)->steppedIn(build);
		level.at(currentPos.below())->steppedOn(build);
		previousElementID = level.at(currentPos)->id;
		
	}
}

void Build::displayPlayer()
{
	printOnLevel(playerChar, currentPos, RED_LIGHT);
	fc::waitMs(movespeed);
	printOnLevel(level.at(currentPos)->symbol, currentPos, level.at(currentPos)->color);
}

