// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Build.h"

#include "LevelElement/LevelElement.h"
#include "Screen/WinScreen/WinScreen.h"
#include <vector>


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
	fc::clearScreen(frameColor);
	if (this->level.start == INVALID_POS) this->level.setStartEnd({ 5,5 }, { level.WIDTH - 6, level.HEIGHT - 6 });

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
			if (this->level.at({ x, y })->symbol == Zombie::ownSym)
			{
				zombieList.push_back(level.at({ x, y }));
				zombieList[zombieList.size() - 1].formPos = { x, y };
				zombieList[zombieList.size() - 1].pos = { x, y };
			}
			content[x + 1][y + 1].content = this->level.at({ x, y })->symbol;
			content[x + 1][y + 1].textColor = this->level.at({ x, y })->getColor();
			content[x + 1][y + 1].backgroundColor = this->level.at({ x,y })->backgroundColor;

			// serach for Stars

			if (this->level.at({ x,y })->id == Star::ownId)
			{
				starPos.push_back({ x,y });
			}

			// serch for timedSpikes
			if (this->level.at({ x,y })->id == TimedSpike::ownId)
			{
				spikePos.push_back({ x,y });
			}

			// serch for timedSpikesAir
			if (this->level.at({ x,y })->id == TimedSpikeAir::ownId)
			{
				spikePos2.push_back({ x,y });
			}

		}
	}

	// star handeling

	if (isEditor)
	{
		this->level.maxElements[Star::ownId] = maxStars;
		this->level.setElements[Star::ownId] = starPos.size();
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

		content[menuPos.x][menuPos.y].textColor = elements[i]->getColor();
		content[menuPos.x][menuPos.y].backgroundColor = elements[i]->backgroundColor;
		menuPos = writeAt(menuPos, elements[i]->symbol);
		menuPos = writeAt(menuPos, " [");
		menuPos = writeAt(menuPos, keybind[i]);
		menuPos = writeAt(menuPos, "] : ");
		countPos[i] = menuPos; // save position of number for later updates

		// checks for infinite blocks
		if (level.maxElements[i] == -1)
			menuPos = writeAt(menuPos, " - ");
		else
			menuPos = writeAt(menuPos, this->level.maxElements[i] - this->level.setElements[i], 3);

		firstIsPlaced = true;

		// new Line when to far right
		if (menuPos.x > WIDTH - 17)
		{
			menuPos.x = 3;
			menuPos.y += 2;
			firstIsPlaced = false;
		}

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
	bool elementPlaced = false;

	
	while (true) // Build loop
	{
		if (_kbhit()) // when key gets pressed
		{
			if (keyHandeling(setElement, dir, cursor)) 
			{
				fc::clearScreen(defaultBackgroundColor);
				return; // leaves editor when e.g. ESC hit or run successfully
			}


			// if there is a new element...
			if (setElement != nullptr)
			{
				elementPlaced = placeOnLevelAt(setElement, cursor.pos); // place element in level object
				cursor.isVisible = !elementPlaced;
			}

			// overprint old element
			printOnLevel(level.at(cursor.pos)->symbol, cursor.pos, level.at(cursor.pos)->getColor(), level.at(cursor.pos)->backgroundColor);

			cursor.move(dir);

			// print cursor 
			if (elementPlaced) printOnLevel(level.at(cursor.pos)->symbol, cursor.pos, level.at(cursor.pos)->getColor(), level.at(cursor.pos)->backgroundColor);
			else printOnLevel(cursor.symbol, cursor.pos, cursor.color);
		}
		else // cursor blinks only when not moveing
		{
			if (cursor.isVisible)
			{	// print cursor
				printOnLevel(cursor.symbol, cursor.pos, cursor.color);
			}
			else
			{	// print current element
				printOnLevel(level.at(cursor.pos)->symbol, cursor.pos, level.at(cursor.pos)->getColor(), level.at(cursor.pos)->backgroundColor);
			}

			
		}
		dir = NONE;
		elementPlaced = false;

		fc::waitMsWithInterupt(500, []() { return (bool)_kbhit(); }); // waits 500ms ore until key is pressed

		cursor.isVisible = !cursor.isVisible; // alternate cursor visibility
	}
}

bool Build::keyHandeling(LevelElement*& setElement, Direction& dir, Cursor cursor)
{

	int key = getCharLow();
	if (key == -32) key = _getch();
	switch (key) // new element keybind here ###################################################################################################################################################
	{
	case 'w':
	case 72:
		dir = UP;
		keyPressedHandeling(setElement);
		break;
	case 'a':
	case 75:
		dir = LEFT;
		keyPressedHandeling(setElement);
		break;
	case 's':
	case 80:
		dir = DOWN;
		keyPressedHandeling(setElement);
		break;
	case 'd':
	case 77:
		dir = RIGHT;
		keyPressedHandeling(setElement);
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
	case Star::ownKey:
		setElement = new Star(true);
		break;
	case NonDelEmpty::ownKey:
		setElement = new NonDelEmpty(true);
		break;
	case TimedSpike::ownKey:
		setElement = new TimedSpike(true);
		break;
	case TimedSpikeAir::ownKey:
		setElement = new TimedSpikeAir(true);
		break;
	case Zombie::ownKey:
		setElement = new Zombie(true);
		break;
	case 13: // Enter
		if (isEditor) return true;
		
		printOnLevel(level.at(cursor.pos)->symbol, cursor.pos, level.at(cursor.pos)->getColor(), level.at(cursor.pos)->backgroundColor);

		if (runLevel()) return true;
		else
		{ // reste after failed runs:
			//set stars to stars again
			starsCollected = 0;
			for (auto & v :starPos)
			{
				level.at(v)->symbol = Star::ownSym;
				printOnLevel(level.at(v)->symbol, v, level.at(v)->getColor(), level.at(v)->backgroundColor);
				
			}

			//reset timed modes
			
			for (auto& v : spikePos)
			{
				level.at(v)->symbol = Spike::ownSym;
				printOnLevel(level.at(v)->symbol, v, level.at(v)->getColor(), level.at(v)->backgroundColor);
			}
			
			for (auto& v : spikePos2)
			{
				level.at(v)->symbol = TimedSpikeAir::ownSym;
				level.at(v)->fallable = false;
				printOnLevel(level.at(v)->symbol, v, level.at(v)->getColor(), level.at(v)->backgroundColor);
			}
			
		}
		break;
		


	case 27: // ESC
		if (leaveConfirm())
		{
			if (isEditor) cancelEdit = true;
			closeSound();

			return true;

		}
		break;

	default:
		dir = NONE;
		break;
	}
	
	if (isEditor && level.at(cursor.pos)->deletable && !cursor.pos.isOnLevelBorder())
	{
		switch (key)
		{
		case ',': // set Start
			//reset old Start
			level.at(level.start)->deletable = true;
			level.at(level.start)->symbol = Empty::ownSym;
			level.at(level.start)->setColor(Screen::defaultTextColor);
			printOnLevel(level.at(level.start)->symbol, level.start, Screen::defaultTextColor);
			
			// set new ones
			setElement = new Empty(false);
			setElement->symbol = Build::startChar;
			setElement->setColor(Build::startColor);

			// update start
			level.start = cursor.pos;
			break;
		case '.': // set End
			//reset old end
			level.at(level.end)->deletable = true;
			level.at(level.end)->symbol = Empty::ownSym;
			level.at(level.end)->setColor(Screen::defaultTextColor);
			printOnLevel(level.at(level.end)->symbol, level.end, Screen::defaultTextColor);
			
			// set new ones
			setElement = new Empty(false);
			setElement->symbol = Build::endChar;
			setElement->setColor(Build::endColor);

			// update end
			level.end = cursor.pos;
			break;
		default:
			break;
		}
	}

	return false;
}

void Build::keyPressedHandeling(LevelElement*& setelement)
{
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		if (fc::isKeyPressed(elements[i]->key))
		{
			setelement = elements[i]->clone();
			setelement->deletable = true;
			return;
		}
	}
	
}





// Runs the Level after build-mode
bool Build::runLevel()
{
	LevelElement* emptying;
	LevelElement* zombie = nullptr;
	/*if (formZombiePos.x != 0 && formZombiePos.y != 0)
	{
		zombieDir = RIGHT;
		zombiePos = formZombiePos;
		zombie = level.at(zombiePos);
	}*/

	currentPos = { level.start.x, level.start.y };
	// reset values
	cycleCount = 1;
	spikey = true;
	spikey2 = true;

	playerGameOver = false;
	playerDirection = RIGHT;
	displayPlayer();

	int repeats;

	t1 = std::chrono::system_clock::now();

	while (!playerGameOver)
	{

		for (int i = 0; i < zombieList.size(); i++)
		{
			zombieList[i].move(build);
		}
		//if (zombie != nullptr)
		//{
		//	if (level.at({ zombiePos.x + zombieDir, zombiePos.y })->id != 0)
		//	{
		//		zombieDir = (zombieDir == RIGHT) ? LEFT : RIGHT;
		//	}
		//	zombie = new Zombie(true);
		//	emptying = new Empty(true);
		//	level.placeAt(emptying, zombiePos.x, zombiePos.y);
		//	//placeOnLevelAt(emptying, zombiePos);
		//	printOnLevel(level.at(zombiePos)->symbol, zombiePos, level.at(zombiePos)->getColor(), level.at(zombiePos)->backgroundColor);
		//	zombiePos.x += zombieDir;
		//	//placeOnLevelAt(zombie, zombiePos);
		//	level.placeAt(zombie, zombiePos.x, zombiePos.y);
		//	printOnLevel(level.at(zombiePos)->symbol, zombiePos, level.at(zombiePos)->getColor(), level.at(zombiePos)->backgroundColor);
		//}


		repeats = 0;
		if (!fc::isKeyPressed(32))	//Space
			movePlayer(playerDirection, 0);
		else movePlayer(0, 0);
		// Falling
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
				t2 = std::chrono::system_clock::now();
				winSound();
				WinScreen winScreen(this);
				winScreen.run();
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
			if (getCharLow() == 27) // Escape
			{
				playerGameOver = true;
			}
		}

		// Win
		if (currentPos == level.end)
		{
			
			return true; 
		}

		// timed exents
		if (cycleCount > 1024) cycleCount = 0;

		if ((cycleCount % spikeCycle) == 0)
		{
			for (auto &v : spikePos)
			{
				level.at(v)->symbol = spikey ? ' ': Spike::ownSym;
				printOnLevel(level.at(v)->symbol, v,level.at(v)->getColor(), level.at(v)->backgroundColor);
			}
			spikey = !spikey;
		}

		if ((cycleCount % spikeCycle2) == 0)
		{
			for (auto &v : spikePos2)
			{
				level.at(v)->symbol = spikey2 ? ' ' : TimedSpikeAir::ownSym;
				level.at(v)->fallable = !spikey;
				printOnLevel(level.at(v)->symbol, v, level.at(v)->getColor(), level.at(v)->backgroundColor);
			}
			spikey2 = !spikey2;
		}

		cycleCount++;
	}
	/*if (formZombiePos.x != 0 && formZombiePos.y != 0 )
	{
		zombie = new Zombie(true);
		emptying = new Empty(true);
		level.placeAt(emptying, zombiePos.x, zombiePos.y);
		printOnLevel(level.at(zombiePos)->symbol, zombiePos, level.at(zombiePos)->getColor(), level.at(zombiePos)->backgroundColor);
		zombiePos = formZombiePos;
		level.placeAt(zombie, zombiePos.x, zombiePos.y);
		printOnLevel(level.at(formZombiePos)->symbol, formZombiePos, level.at(formZombiePos)->getColor(), level.at(formZombiePos)->backgroundColor);
	}*/

	for (int i = 0; i < zombieList.size(); i++)
	{
		zombieList[i].reset(build);
	}
	// Display dead Player
	printOnLevel(playerDeadChar, currentPos, BLUE_LIGHT, level.at(currentPos)->backgroundColor);
	deathSound(); // also waits
	printOnLevel(level.at(currentPos)->symbol, currentPos, level.at(currentPos)->getColor(), level.at(currentPos)->backgroundColor);
	return false;
}

// checks wether a block could be placed and does so
bool Build::placeOnLevelAt(LevelElement*& element, Pos pos)
{
	// Handeling limited Blocks
	int &id = element->id;
	int& oldId = level.at(pos)->id;
	int &x = pos.x;
	int &y = pos.y;

	if ((level.setElements[id] < level.maxElements[id] || level.maxElements[id] == -1) && level.at({ x, y })->deletable) // when allowed to place
	{

		// take care of stars
		//if (id == Star::ownId) starPos.push_back(pos);
		
		level.setElements[oldId]--; // decrement deleted

		level.setElements[id]++; // increment new

		// colors for number replacement
		fc::setBackgroundColor(frameColor);
		fc::setTextColor(frameTextColor);

		//replace number in display : old Element (unless max is empty or inf. or 0)
		if (oldId != 0 && level.maxElements[oldId] != -1 && level.maxElements[oldId] != 0)
		{
			
			fc::setCursorPos(countPos[oldId].x, countPos[oldId].y);
			std::cout << std::setw(3) << (level.maxElements[oldId] - level.setElements[oldId]);
		}

		// new Element display update (unless max is empty or inf. or 0)
		if (id != 0 && level.maxElements[id] != -1 && level.maxElements[id] != 0)
		{
			fc::setCursorPos(countPos[id].x, countPos[id].y);
			std::cout << std::setw(3) << (level.maxElements[id] - level.setElements[id]);
		}

		level.placeAt(element, x, y);
		element = nullptr;
		return true;

	}
	else
	{
		delete element;
		element = nullptr;
		return false;
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
		if ((level.at(currentPos)->id == 2 && level.at(currentPos)->id != previousElementID )|| (level.at(currentPos)->id == 3 && level.at(currentPos)->id != previousElementID))
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

	if(fc::isKeyPressed('w') || fc::isKeyPressed(72))
		fc::waitMs(movespeed / 5);
	else if (fc::isKeyPressed('s'))
		fc::waitMs(movespeed * 3);
	else fc::waitMs(movespeed);
	printOnLevel(level.at(currentPos)->symbol, currentPos, level.at(currentPos)->getColor(), level.at(currentPos)->backgroundColor);
}

bool Build::leaveConfirm()
{
	fc::setBackgroundColor(frameColor);
	fc::setTextColor(BLACK);
	Pos textPos = { 3, Screen::HEIGHT - 3 };

	if (isEditor) textPos.y = 0;
	std::string text = "Wirklich verlassen? [ENTER]";
	gotoxy(textPos.x, textPos.y);
	std::cout << text;
	if (_getch() == 13)
		return true;
	gotoxy(textPos.x, textPos.y);
	for (int i = 0; i < text.length(); i++)
	{
		std::cout << " ";
	}
	return false;
}
