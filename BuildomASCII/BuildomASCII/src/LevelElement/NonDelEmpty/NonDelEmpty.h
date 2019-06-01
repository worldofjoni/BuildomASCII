// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef NON_DEL_EMPTY_H
#define NON_DEL_EMPTY_H

#include "LevelElement/LevelElement.h"


class NonDelEmpty : public LevelElement
{
public:
	static const char ownSym = ' ';
	static const char ownKey = '6';
	static const int ownId = 7;
	NonDelEmpty(bool deletable);
	void steppedOn(Build *build) override;
	void steppedIn(Build *build) override;
	NonDelEmpty* clone() override;
	
};

#endif // !NON_DEL_EMPTY_H