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
	Level(int with, int height);

	~Level(); // Rule of vive
	Level(const Level& other); // Copy Constructor
	Level(Level&& other) = delete; // Move Constructor
	Level& operator=(const Level& other) = delete; // copy asignment
	Level& operator=(Level&& other) = delete; // move asignment


};




#endif // !LEVEL_H
