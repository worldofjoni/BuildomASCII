// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Level.h"
#include "LevelElement/Empty/Empty.h"
#include "Screen/Build/Build.h"


void Level::swap(Pos pos1, Pos pos2)
{
	LevelElement* el = at(pos1);
	at(pos1) = at(pos2);
	at(pos2) = el;
}

// constructor
Level::Level()
{
	// set map to Empty
	map = new LevelElement **[WIDTH];

	for (int x = 0; x < WIDTH; x++)
	{
		map[x] = new LevelElement* [HEIGHT];
		for (int y = 0; y < HEIGHT; y++)
		{
			map[x][y] = new Empty(true);
		}
	}


	// init maxElements to -1
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		maxElements[i] = -1;
	}


	// init border to red background
	for (int x = 0; x < WIDTH; x++)
	{
		at({ x, 0 })->backgroundColor = Build::alarmFrameColor;
		at({ x, HEIGHT -1 })->backgroundColor = Build::alarmFrameColor;
	}
	for (int y = 0; y < HEIGHT; y++)
	{
		at({ 0, y })->backgroundColor = Build::alarmFrameColor;
		at({ WIDTH -1,y })->backgroundColor = Build::alarmFrameColor;
	}
}

// replaces Element at position (with deleation)
void Level::placeAt(LevelElement* element, int x, int y)
{
	Pos pos = { x,y };

	// check for Border and set alarmColor (only if not...
	if (pos.isOnLevelBorder() && !(element->id == NonDelEmpty::ownId || element->id == TimedSpike::ownId)) 
		element->backgroundColor = Build::alarmFrameColor;

	delete map[x][y];
	map[x][y] = element;
	element = nullptr;
}

void Level::setMaxElements(int list[LevelElement::countOfElements])
{
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		maxElements[i] = list[i];
	}
}

void Level::setStartEnd(Pos start, Pos end)
{
	this->start = start;
	this->end = end;

	at(this->start)->setColor(Build::startColor);
	at(this->start)->symbol = Build::startChar;
	at(this->start)->deletable = false;

	at(this->end)->setColor(Build::endColor);
	at(this->end)->symbol = Build::endChar;
	at(this->end)->deletable = false;
}

LevelElement*& Level::at(Pos pos)
{
	return map[pos.x][pos.y];
}


// destructor
Level::~Level()
{
	if (map != nullptr)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				delete map[x][y];
				map[x][y] = nullptr;
			}
			delete[] map[x];
			map[x] = nullptr;
		}
		delete[] map;
		map = nullptr;
	}
}

// copy constructor
Level::Level(const Level& other)
	: start(other.start), end(other.end)
{
	map = new LevelElement** [WIDTH];

	for (int i = 0; i < WIDTH; i++)
	{
		map[i] = new LevelElement * [HEIGHT];
	}

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			map[x][y] = other.map[x][y]->clone();
		}
	}

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		this->maxElements[i] = other.maxElements[i];
		this->setElements[i] = other.setElements[i];
	}
}

// move constructor
Level::Level(Level && other)
	:start(other.start), end(other.end)
{
	
	map = other.map;
	other.map = nullptr;

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		maxElements[i] = other.maxElements[i];
		setElements[i] = other.setElements[i];
	}
}

// copy asignment
Level& Level::operator=(const Level& other)
{
	start = other.start;
	end = other.end;

	// delete old
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			delete map[x][y];
			map[x][y] = nullptr;
		}
		delete[] map[x];
		map[x] = nullptr;
	}
	delete[] map;

	// copy new
	map = new LevelElement * *[WIDTH];

	for (int i = 0; i < WIDTH; i++)
	{
		map[i] = new LevelElement * [HEIGHT];
	}

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			map[x][y] = other.map[x][y]->clone();
		}
	}

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		this->maxElements[i] = other.maxElements[i];
		this->setElements[i] = other.setElements[i];
	}

	return *this;
}

// move asignment
Level& Level::operator=(Level&& other)
{
	if (this != &other)
	{
		start = other.start, end = other.end;
		
		// delete to overwrite with new
		for (int x = 0; x < WIDTH; x++)
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				delete map[x][y];
				map[x][y] = nullptr;
			}
			delete[] map[x];
			map[x] = nullptr;
		}
		delete[] map;



		map = other.map;
		other.map = nullptr;

		for (int i = 0; i < LevelElement::countOfElements; i++)
		{
			maxElements[i] = other.maxElements[i];
			setElements[i] = other.setElements[i];
		}
	}
	return *this;
}
