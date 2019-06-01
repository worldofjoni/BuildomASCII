// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "LevelElement/LevelElement.h"
#include "Screen/Screen.h"


class Level
{
private:
	LevelElement ***map = nullptr;

public:
	// Constructor / Destructor
	Level();
	~Level(); // Rule of five
	Level(const Level& other); // Copy Constructor
	Level(Level&& other); // Move Constructor
	Level& operator=(const Level& other); // copy asignment
	Level& operator=(Level&& other); // move asignment


	// General functions
	void placeAt(LevelElement *element, int x, int y);
	void setMaxElements(int list[LevelElement::countOfElements]);
	void setStartEnd(Pos start, Pos end);
	void swap(Pos pos1, Pos pos2);
	LevelElement*& at(Pos pos);


	// General variables
	static const int WIDTH = Screen::WIDTH - 2, HEIGHT = Screen::HEIGHT - 10;
	int maxElements[LevelElement::countOfElements] = {}; // index is id of element ; for unlimited use -1
	int setElements[LevelElement::countOfElements] = {}; // index is id of element
	Pos start = INVALID_POS;
	Pos end = INVALID_POS;
};

#endif // !LEVEL_H
