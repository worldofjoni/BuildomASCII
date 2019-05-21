#pragma once
#ifndef LEVEL_H
#define LEVEL_H
#include "LevelElement/LevelElement.h"
#include "Screen/Screen.h"

#define INVALID -1


class Level
{
private:
	LevelElement ***map;
public:
	const int WIDTH = Screen::WIDTH - 2, HEIGHT = Screen::HEIGHT - 10;
	int maxElements[LevelElement::countOfElements] = {}; // index is id of element ; for unlimited use -1
	int setElements[LevelElement::countOfElements] = {}; // index is id of element

	Pos start = { INVALID, INVALID };
	Pos end = { INVALID,  INVALID};


	Level();
	void placeAt(LevelElement *element, int x, int y);
	void setMaxElements(int list[LevelElement::countOfElements]);
	void setStartEnd(Pos start, Pos end);

	LevelElement* at(Pos pos);

	~Level(); // Rule of five
	Level(const Level& other); // Copy Constructor
	Level(Level&& other); // Move Constructor
	Level& operator=(const Level& other); // copy asignment
	Level& operator=(Level&& other); // move asignment


};




#endif // !LEVEL_H
