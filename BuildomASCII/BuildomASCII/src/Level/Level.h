#pragma once
#ifndef LEVEL_H
#define LEVEL_H
#include "LevelElement/LevelElement.h"
#include "Screen/Screen.h"



class Level
{
private:
public:
	const int WIDTH = Screen::WIDTH - 2, HEIGHT = Screen::HEIGHT - 10;
	LevelElement ***map;
	int maxElements[LevelElement::countOfElements] = {}; // index is id of element ; for unlimited use -1
	int setElements[LevelElement::countOfElements] = {}; // index is id of element

	Pos start = { 5, 5 };
	Pos end = { WIDTH - 5, HEIGHT - 5 };


	Level();
	void placeAt(LevelElement *element, int x, int y);
	void setMaxElements(int list[LevelElement::countOfElements]);
	void setStartEnd(Pos start, Pos end);

	~Level(); // Rule of five
	Level(const Level& other); // Copy Constructor
	Level(Level&& other) = delete; // Move Constructor
	Level& operator=(const Level& other); // copy asignment
	Level& operator=(Level&& other) = delete; // move asignment


};




#endif // !LEVEL_H
