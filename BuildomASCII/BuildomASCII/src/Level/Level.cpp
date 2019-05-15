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

	setStartEnd(start, end);

}


// replaces Element at position (with deleation)
void Level::placeAt(LevelElement *element, int x, int y)
{
	
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

	map[start.x][start.y]->color = Build::startColor;
	map[start.x][start.y]->symbol = Build::startChar;
	map[start.x][start.y]->deletable = false;

	map[end.x][end.y]->color = Build::endColor;
	map[end.x][end.y]->symbol = Build::endChar;
	map[end.x][end.y]->deletable = false;


}


// destructor
Level::~Level()
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


