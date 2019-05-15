#pragma once
#ifndef BUILD_H
#define BUILD_H

#include "Screen/Screen.h"
#include "Level/Level.h"
#include "friendlyConsole/friendlyConsole.hpp"

class Cursor;

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

	template <typename T>
	void printOnLevel(T content, int x, int y, fc::Color color = defaultTextColor, fc::Color backgroundColor = defaultBackgroundColor);

	const fc::Color frameColor = DARK_GRAY, frameTextColor = BLACK;
	const fc::Color menuBarSymColor = RED, menuBarLineColor = BLUE_LIGHT;

	//for levelEditor
	bool isEditor = false;

	// for runLevel
	Build* build = this;
	int fallSpeed = 3;

	char symbols[LevelElement::countOfElements] = { Empty::ownSym, Solid::ownSym, SlopeUp::ownSym, SlopeDown::ownSym, ChangeDir::ownSym , Spike::ownSym}; // has to be manualy updated ############################################################
	char keybind[LevelElement::countOfElements][10] = { "BACK", "SPACE", {SlopeUp::ownKey}, {SlopeDown::ownKey}, {ChangeDir::ownKey} , {Spike::ownKey} }; // same; !! for surround single chars with curly bracets !! ##########################################

public:
	Level level;
	const static char startChar = '#', endChar = 'P', playerChar = 2, playerDeadChar = 1;
	const static fc::Color startColor = MAGENTA, endColor = GREEN_LIGHT;

	Build(Level level, bool asEditor = false);
	void run();
	bool keyHandeling(LevelElement *&setElement, Direction &dir, Cursor cursor);
	

	bool runLevel(Level level);
	
	Pos countPos[LevelElement::countOfElements]; // index is id of element
	void placeOnLevelAt(LevelElement*& element, int x, int y);


	// For runLevel
	Pos currentPos = { 0,0 };
	bool playerGameOver = false;
	Direction playerDirection;

	// for level Editor
	void setValues(); // sets start, end, maxElements
	

	
	



};



#endif
