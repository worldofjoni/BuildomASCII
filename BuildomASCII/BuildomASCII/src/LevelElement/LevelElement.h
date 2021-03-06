// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef LEVEL_ELEMENT_H
#define LEVEL_ELEMENT_H

#include "pch/pch.h"
#include "Screen/Screen.h"


class Build;

class LevelElement
{
protected:
	fc::Color color;

public:
	// Variables
	char symbol, key;
	int id;
	bool deletable = true; // If an Element can be removed by player
	bool fallable = false; // If an Element can be fallen through
	bool canBePlacedByUser = true;
	fc::Color backgroundColor = Screen::defaultBackgroundColor;
	
	// Functions
	fc::Color getColor();
	void setColor(fc::Color col);
	virtual void steppedOn(Build *build) = 0;
	virtual void steppedIn(Build *build) = 0;
	virtual LevelElement* clone() = 0; // copy function

	
	static const int countOfElements = 11; // num of different element, hs to be manualy updated, also update the list in Build!! && in BdalManager###############################
};


#include "Empty/Empty.h"
#include "Solid/Solid.h"
#include "SlopeUp/SlopeUp.h"
#include "SlopeDown/SlopeDown.h"
#include "ChangeDir/ChangeDir.h"
#include "Spike/Spike.h"
#include "Star/Star.h"
#include "NonDelEmpty/NonDelEmpty.h"
#include "TimedSpike/TimedSpike.h"
#include "TimedSpikeAir/TimedSpikeAir.h"
#include "Zombie/Zombie.h"

#endif // !LEVEL_ELEMENT_H