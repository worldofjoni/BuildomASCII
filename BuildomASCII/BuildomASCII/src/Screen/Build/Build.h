#pragma once
#ifndef BUILD_H
#define BUILD_H
#include "Screen/Screen.h"
#include "Level/Level.h"
#include "friendlyConsole/friendlyConsole.hpp"
#include "Cursor/Cursor.h"


enum Direction
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

class Build : public Screen
{
private:
	Level level;

	template <typename T>
	void printOnLevel(T content, int x, int y, fc::Color color = defaultTextColor, fc::Color backgroundColor = defaultBackgroundColor);

	const fc::Color frameColor = DARK_GRAY, frameTextColor = BLACK;
	char startChar = '#', endChar = 'P', playerChar = 2, playerDeadChar = 1;

	
	Build* build = this;
	int fallSpeed = 3;

public:
	Build(Level level);
	void run();
	bool keyHandeling(LevelElement *&setElement, Direction &dir, bool &enteredRun);
	

	bool runLevel(Level level);
	
	Pos countPos[LevelElement::countOfElements]; // index is id of element
	void placeOnLevelAt(LevelElement*& element, int x, int y);


	// For runLevel
	Pos currentPos = { 0,0 };
	bool playerGameOver = false;
	Direction playerDirection;

	
	



};



#endif
