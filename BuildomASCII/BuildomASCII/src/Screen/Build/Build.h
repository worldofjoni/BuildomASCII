// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef BUILD_H
#define BUILD_H

#include "Screen/Screen.h"
#include "Level/Level.h"
#include "pch/pch.h"


class Cursor;

class Build : public Screen
{
public:
	static const int maxStars = 3;

private:

	// Layout Variables
	const fc::Color frameColor = DARK_GRAY, frameTextColor = BLACK;
	const fc::Color menuBarSymColor = RED, menuBarLineColor = BLUE_LIGHT, menuBarSymbolBackgroundColor = LIGHT_GRAY;


	//for levelEditor
	bool isEditor = false;


	// for runLevel
	int movespeed = 100;
	bool leaveConfirm();
	

	// ++ Special Blocks ++
	// Star
	std::vector<Pos> starPos;

	// Timed Spike
	std::vector<Pos> spikePos;
	const int spikeCycle = 10;

	// Timed Spike Air
	std::vector<Pos> spikePos2;
	const int spikeCycle2 = 10;

	//Zombie
	std::vector<Zombie> zombieList;
	Pos zombiePos = { 0, 0 };
	Pos formZombiePos = { 0, 0 };
	Direction zombieDir = RIGHT;

public:

	// Constructor / Destructor
	Build(Level level, bool asEditor = false);
	~Build();
	Build(const Build& other) = delete;
	Build(Build&& other) = delete;
	Build& operator=(const Build& other) = delete;
	Build& operator=(Build&& other) = delete;


	// For runLevel
	int fallSpeed = 3;


	// Basic Functions
	template <typename T>
	void printOnLevel(T content, Pos pos, fc::Color color = defaultTextColor, fc::Color backgroundColor = defaultBackgroundColor);
	bool placeOnLevelAt(LevelElement*& element, Pos pos);

	void run();
	bool keyHandeling(LevelElement *&setElement, Cursor& cursor);
	void keyPressedHandeling(LevelElement*& setelement);

	bool runLevel();
	void displayPlayer(int timer = 0);
	void movePlayer(int xOffset, int yOffset);


	// Content Variables
	Level level;
	LevelElement* elements[LevelElement::countOfElements] = {  new Empty(false), new Solid(false), new SlopeUp(false), new SlopeDown(false), new ChangeDir(false), new Spike(false), new Star(false), new NonDelEmpty(false), new TimedSpike(false), new TimedSpikeAir(false) , new Zombie(false)}; // List of alle Elments, index is ID ##########################################


	// Layout Variables
	const static char startChar = '#', endChar = 'P', playerChar = 2, playerDeadChar = 1;
	const static fc::Color startColor = MAGENTA, endColor = GREEN, alarmFrameColor = RED_LIGHT;
	Pos remainingCountPos[LevelElement::countOfElements]; // index is id of element
	char keybind[LevelElement::countOfElements][10] = { "BACK", "SPACE", {SlopeUp::ownKey}, {SlopeDown::ownKey}, {ChangeDir::ownKey} , {Spike::ownKey}, {Star::ownKey}, {NonDelEmpty::ownKey}, {TimedSpike::ownKey} , {TimedSpikeAir::ownKey}, {Zombie::ownKey} }; // surround single chars with curly bracets ##########################################


	// runLevel Variables
	bool playerGameOver = false;
	Pos currentPos = { 0,0 };
	Pos previousPos = currentPos;
	Direction playerDirection;
	int previousElementID = -1;
	int previousLowerElementID = -1;
	int cycleCount = 1;
	std::chrono::system_clock::time_point t1, t2;
	
	// Level Editor Variables
	bool cancelEdit = false;

	// For Blocks
	int starsCollected = 0;
	bool spikey = true;
	bool spikey2 = true;

};



#endif
