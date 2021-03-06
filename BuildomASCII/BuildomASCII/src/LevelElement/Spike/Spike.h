// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef SPIKE_H
#define SPIKE_H

#include "LevelElement/LevelElement.h"

class Spike : public LevelElement
{
private:
public:
	static const char ownSym = 30;
	static const char ownKey = '4';
	static const int ownId = 5;
	Spike(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	Spike* clone() override;
};


#endif // !SPIKE_H
