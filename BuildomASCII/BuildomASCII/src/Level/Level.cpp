#include "pch/pch.h"
#include "Level.h"
#include "LevelElement/Empty/Empty.h"


// constructor
Level::Level()
{
	map = new LevelElement * *[WIDTH];

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

	// init border to red bäckground

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
	// check for Border and set alarmColor
	Pos pos = { x,y };
	if (pos.isOnLevelBorder()) element->backgroundColor = Build::alarmFrameColor;


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

	map[this->start.x][this->start.y]->setColor(Build::startColor);
	map[this->start.x][this->start.y]->symbol = Build::startChar;
	map[this->start.x][this->start.y]->deletable = false;

	map[this->end.x][this->end.y]->setColor(Build::endColor);
	map[this->end.x][this->end.y]->symbol = Build::endChar;
	map[this->end.x][this->end.y]->deletable = false;


}

LevelElement* Level::at(Pos pos)
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

Level& Level::operator=(Level&& other)
{
	start = other.start, end = other.end;
	
	map = other.map;
	other.map = nullptr;

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		maxElements[i] = other.maxElements[i];
		setElements[i] = other.setElements[i];
	}
	return *this;
}
