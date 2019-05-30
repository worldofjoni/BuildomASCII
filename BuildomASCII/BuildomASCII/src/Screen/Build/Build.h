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
	std::vector<Zombie> zombieList;
	Pos zombiePos = { 0, 0 };
	Pos formZombiePos = { 0, 0 };
	Direction zombieDir = RIGHT;

	const fc::Color frameColor = DARK_GRAY, frameTextColor = BLACK;
	const fc::Color menuBarSymColor = RED, menuBarLineColor = BLUE_LIGHT, menuBarSymbolBackgroundColor = LIGHT_GRAY;

	//for levelEditor
	bool isEditor = false;

	// for runLevel
	Build* build = this;
	int movespeed = 100;

	bool leaveConfirm();


public:
	int fallSpeed = 3;
	template <typename T>
	void printOnLevel(T content, Pos pos, fc::Color color = defaultTextColor, fc::Color backgroundColor = defaultBackgroundColor);
	void displayPlayer();

	
	Level level;
	const static char startChar = '#', endChar = 'P', playerChar = 2, playerDeadChar = 1;
	const static fc::Color startColor = MAGENTA, endColor = GREEN, alarmFrameColor = RED_LIGHT;

	Build(Level level, bool asEditor = false);
	void run();
	bool keyHandeling(LevelElement *&setElement, Direction &dir, Cursor cursor);
	void keyPressedHandeling(LevelElement*& setelement);

	bool runLevel();
	
	Pos countPos[LevelElement::countOfElements]; // index is id of element
	bool placeOnLevelAt(LevelElement*& element, Pos pos);

	LevelElement* elements[LevelElement::countOfElements] = {  new Empty(false), new Solid(false), new SlopeUp(false), new SlopeDown(false), new ChangeDir(false), new Spike(false), new Star(false), new NonDelEmpty(false), new TimedSpike(false), new TimedSpikeAir(false) , new Zombie(false)};// has to be manualy updated ############################################################
	char keybind[LevelElement::countOfElements][10] = { "BACK", "SPACE", {SlopeUp::ownKey}, {SlopeDown::ownKey}, {ChangeDir::ownKey} , {Spike::ownKey}, {Star::ownKey}, {NonDelEmpty::ownKey}, {TimedSpike::ownKey} , {TimedSpikeAir::ownKey}, {Zombie::ownKey} }; // same; !! for surround single chars with curly bracets !! ##########################################

	// For runLevel
	Pos currentPos = { 0,0 };
	bool playerGameOver = false;
	Direction playerDirection;
	void movePlayer(int xOffset, int yOffset);
	int previousElementID = -1;
	int previousLowerElementID = -1;

	int cycleCount = 1;

	Pos previousPos = currentPos;

	std::chrono::system_clock::time_point t1, t2;

	//for star
	std::vector<Pos> starPos;
	int starsCollected = 0;
	

	// For timed spike
	std::vector<Pos> spikePos;
	const int spikeCycle = 10;
	bool spikey = true;

	//for 2. Timed Spike
	std::vector<Pos> spikePos2;
	const int spikeCycle2 = 10;
	bool spikey2 = true;

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
