#pragma once
#ifndef BUILD_H
#define BUILD_H
#include "Screen/Screen.h"
#include "Level/Level.h"






class Build : public Screen
{
private:
	Level level;



public:
	Build(Level level);
	void run();



};



#endif