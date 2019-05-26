// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef CHANGEDIR_H
#define CHANGEDIR_H

#include "LevelElement/LevelElement.h"

class ChangeDir : public LevelElement
{
private:
public:
	static const char ownSym = 29;
	static const char ownKey = '3';
	static const int ownId = 4;
	ChangeDir(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	ChangeDir* clone() override;
};

#endif // !CHANGEDIR_H
