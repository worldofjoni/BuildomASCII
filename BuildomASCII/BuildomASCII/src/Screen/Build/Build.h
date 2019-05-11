#pragma once
#ifndef BUILD_H
#define BUILD_H
#include "Screen/Screen.h"
#include "Level/Level.h"
#include "friendlyConsole/friendlyConsole.hpp"
 



class Build : public Screen
{
private:
	Level level;

	template <typename T>
	void printOnLevel(T content, int x, int y, fc::Color color = defaultTextColor, fc::Color backgroundColor = defaultBackgroundColor);

	const fc::Color frameColor = DARK_GRAY, frameTextColor = BLACK;
	char startChar = '#', endChar = 'P';

public:
	Build(Level level);
	void run();
	
	Pos countPos[LevelElement::countOfElements]; // index is id of element
	void placeOnLevelAt(LevelElement*& element, int x, int y);


	
	



};



#endif
