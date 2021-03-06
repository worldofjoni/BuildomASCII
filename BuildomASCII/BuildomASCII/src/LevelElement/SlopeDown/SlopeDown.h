// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef SLOPE_DOWN_H
#define SLOPE_DOWN_H

#include "LevelElement/LevelElement.h"


class SlopeDown : public LevelElement
{
public:
	static const char ownSym = '\\';
	static const char ownKey = '2';
	static const int ownId = 3;
	SlopeDown(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	SlopeDown* clone() override;
};

#endif // !SLOPE_DOWN_H
