// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef STAR_H
#define STAR_H

#include "LevelElement/LevelElement.h"


class Star : public LevelElement
{
public:
	static const char ownSym = 15;
	static const char ownKey = '5';
	static const int ownId = 6;
	Star(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	Star* clone() override;
};

#endif // ! STAR_H
