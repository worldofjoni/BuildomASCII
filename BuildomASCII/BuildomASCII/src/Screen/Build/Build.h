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
	UP = 3,
	DOWN = 2,
	LEFT = -1,
	RIGHT = 1,
};

class Build : public Screen
{
public:
	static const int maxStars = 3;

private:



	const fc::Color frameColor = DARK_GRAY, frameTextColor = BLACK;
	const fc::Color menuBarSymColor = RED, menuBarLineColor = BLUE_LIGHT, menuBarSymbolBackgroundColor = LIGHT_GRAY;

	//for levelEditor
	bool isEditor = false;

	// for runLevel
	Build* build = this;
	int fallSpeed = 2;
	int movespeed = 100;
	void displayPlayer();
	//for stars
	int starsPlaced = 0;
	Pos starsPos[maxStars] = { INVALID_POS, INVALID_POS, INVALID_POS };

	template <typename T>
	void printOnLevel(T content, Pos pos, fc::Color color = defaultTextColor, fc::Color backgroundColor = defaultBackgroundColor);

public:

	int stars = 0;
	Level level;
	const static char startChar = '#', endChar = 'P', playerChar = 2, playerDeadChar = 1;
	const static fc::Color startColor = MAGENTA, endColor = GREEN, alarmFrameColor = RED;

	Build(Level level, bool asEditor = false);
	void run();
	bool keyHandeling(LevelElement *&setElement, Direction &dir, Cursor cursor);
	void keyPressedHandeling(LevelElement*& setelement);

	bool runLevel();
	
	Pos countPos[LevelElement::countOfElements]; // index is id of element
	bool placeOnLevelAt(LevelElement*& element, Pos pos);

	LevelElement* elements[LevelElement::countOfElements] = {  new Empty(false), new Solid(false), new SlopeUp(false), new SlopeDown(false), new ChangeDir(false), new Spike(false), new Star(false), new NonDelEmpty(false) };// has to be manualy updated ############################################################
	char keybind[LevelElement::countOfElements][10] = { "BACK", "SPACE", {SlopeUp::ownKey}, {SlopeDown::ownKey}, {ChangeDir::ownKey} , {Spike::ownKey}, {Star::ownKey}, {NonDelEmpty::ownKey} }; // same; !! for surround single chars with curly bracets !! ##########################################

	// For runLevel
	Pos currentPos = { 0,0 };
	bool playerGameOver = false;
	Direction playerDirection;
	void movePlayer(int xOffset, int yOffset);
	int previousElementID = -1;
	int previousLowerElementID = -1;

	Pos previousPos = currentPos;

	// for level Editor
	bool cancelEdit = false;
	
	
	// destructor
	~Build();
	Build(const Build& other) = delete;
	Build(Build&& other) = delete;
	Build& operator=(const Build& other) = delete;
	Build& operator=(Build&& other) = delete;
	


};



#endif
