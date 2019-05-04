#include "pch/pch.h"
#include "Level.h"
#include "LevelElement/Empty/Empty.h"


// constructor
Level::Level(int with, int height)
	: WIDTH(with), HEIGHT(height)
{
	map = new LevelElement** [WIDTH];

	for (int x = 0; x < WIDTH; x++)
	{
		map[x] = new LevelElement* [HEIGHT];
		for (int y = 0; y < HEIGHT; y++)
		{
			map[x][y] = new Empty;
		}
	}

	

}

void Level::addAt(LevelElement *&element, int x, int y)
{
	// Handeling limited Blocks
	int id = element->id;

	if (setElements[id] < maxElements[id] || maxElements[id] == -1)
	{
		setElements[map[x][y]->id]--; // decrement deleted

		setElements[id]++; // increment new

		delete map[x][y];
		map[x][y] = element;
		element = nullptr;

	}
	else
	{
		delete element;
		element = nullptr;
	}

}

void Level::setMaxElements(int list[LevelElement::countOfElements])
{
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		maxElements[i] = list[i];
	}
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
	:WIDTH(other.WIDTH), HEIGHT(other.HEIGHT)
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


