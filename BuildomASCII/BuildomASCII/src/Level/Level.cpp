#include "../pch/pch.h"
#include "Level.h"



Level::Level(int with, int height)
	: WIDTH(with), HEIGHT(height)
{
	map = new LevelElement** [WIDTH];

	for (int i = 0; i < WIDTH; i++)
	{
		map[i] = new LevelElement* [HEIGHT];
	}

}



Level::~Level()
{
	for (int i = 0; i < WIDTH; i++)
	{
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
}