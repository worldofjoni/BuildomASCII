#pragma once
#ifndef LEVEL_H
#define LEVEL_H
#include "LevelElement/LevelElement.h"

class Level
{
private:
public:
	const int WIDTH, HEIGHT;
	LevelElement ***map;
	int maxElements[LevelElement::countOfElements] = {}; // index is id of element ; for unlimited use -1
	int setElements[LevelElement::countOfElements] = {}; // index is id of element ; for unlimited use -1
	Level(int with, int height);
	void addAt(LevelElement *&element, int x, int y);
	void setMaxElements(int list[LevelElement::countOfElements]);

	~Level(); // Rule of vive
	Level(const Level& other); // Copy Constructor
	Level(Level&& other) = delete; // Move Constructor
	Level& operator=(const Level& other) = delete; // copy asignment
	Level& operator=(Level&& other) = delete; // move asignment


};




#endif // !LEVEL_H
