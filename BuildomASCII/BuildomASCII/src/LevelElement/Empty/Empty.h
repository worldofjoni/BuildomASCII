// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef EMPTY_H
#define EMPTY_H

#include "LevelElement/LevelElement.h"


class Empty : public LevelElement
{
public:
	static const char ownSym = ' ';
	static const char ownKey = 8;
	static const int ownId = 0;
	Empty(bool deletable);
	void steppedOn(Build *build) override;
	void steppedIn(Build *build) override;
	Empty* clone() override;
};

#endif // !EMPTY_H