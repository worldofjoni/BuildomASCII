// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef SOLID_H
#define SOLID_H

#include "LevelElement/LevelElement.h"


class Solid : public LevelElement
{
public:
	static const char ownSym = 219;
	static const char ownKey = ' ';
	static const int ownId = 1;
	static const fc::Color ownColor = BLACK;
	Solid(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	Solid* clone() override;
};

#endif // !SOLID_H