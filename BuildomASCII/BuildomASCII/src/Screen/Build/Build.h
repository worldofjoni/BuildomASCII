#pragma once
#ifndef BUILD_H
#define BUILD_H
#include "Screen/Screen.h"
#include "Level/Level.h"
#include "friendlyConsole/friendlyConsole.hpp"
#include "Cursor/Cursor.h"


enum Direction;

class Build : public Screen
{
private:

	template <typename T>
	void printOnLevel(T content, int x, int y, fc::Color color = defaultTextColor, fc::Color backgroundColor = defaultBackgroundColor);

	const fc::Color frameColor = DARK_GRAY, frameTextColor = BLACK;
	char startChar = '#', endChar = 'P', playerChar = 2, playerDeadChar = 1;

	
	Build* build = this;
	int fallSpeed = 3;

public:
	Level level;
	Build(Level level);
	void run();

	bool runLevel( );
	
	Pos countPos[LevelElement::countOfElements]; // index is id of element
	void placeOnLevelAt(LevelElement*& element, int x, int y);


	// For runLevel
	Pos currentPos = { 0,0 };
	bool playerGameOver = false;
	Direction playerDirection;
	void movePlayer(int xOffset, int yOffset);
	int previousElementID = -1;
	Pos previousPos = currentPos;

	
	



};



#endif