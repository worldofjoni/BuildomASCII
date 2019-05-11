#pragma once
#ifndef LEVEL_ELEMENT_H
#define LEVEL_ELEMENT_H

#include "pch/pch.h"
#include "Position/Pos.h"

class LevelElement
{
public:
	char symbol;
	int id;
	bool deletable = true; // If an Element can be removed By player

	
	virtual bool steppedOn(Pos &pos) = 0;
	virtual bool steppedIn(Pos &pos) = 0;

	virtual LevelElement* clone() = 0; // copy function
	fc::Color color;
	static const int countOfElements = 4; // num of different element

};


#include "Empty/Empty.h"
#include "Solid/Solid.h"
#include "SlopeUp/SlopeUp.h"
#include "SlopeDown/SlopeDown.h"



#endif // !LEVEL_ELEMENT_H