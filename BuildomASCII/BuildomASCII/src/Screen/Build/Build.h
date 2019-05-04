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

	const fc::Color frameColor = DARK_GRAY;


public:
	Build(Level level);
	void run();
	



};



#endif
