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
	const fc::Color menuBarSymColor = RED, menuBarLineColor = BLUE_LIGHT;

	
	Build* build = this;
	int fallSpeed = 3;

	char symbols[LevelElement::countOfElements] = { Empty::ownSym, Solid::ownSym, SlopeUp::ownSym, SlopeDown::ownSym, ChangeDir::ownSym , Spike::ownSym}; // has to be manualy updated ############################################################
	char keybind[LevelElement::countOfElements][10] = { "BACK", "SPACE", {SlopeUp::ownKey}, {SlopeDown::ownKey}, {ChangeDir::ownKey} , {Spike::ownKey} }; // same; !! for surround single chars with curly bracets !! ##########################################

public:
	const static char startChar = '#', endChar = 'P', playerChar = 2, playerDeadChar = 1;

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
