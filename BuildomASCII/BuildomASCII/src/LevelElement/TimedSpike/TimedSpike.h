// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef TIMED_SPIKE_H
#define TIMED_SPIKE_H

#include "LevelElement/LevelElement.h"


class TimedSpike : public LevelElement
{
public:
	static const char ownSym = 30;
	static const char ownKey = '7';
	static const int ownId = 8;
	static const fc::Color ownColor = RED;
	static const fc::Color disabledColor = DARK_GRAY;
	TimedSpike(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	TimedSpike* clone() override;
};

#endif // ! TIMED_SPIKE_H
