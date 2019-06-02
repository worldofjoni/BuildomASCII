// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef TIMED_SPIKE_AIR_H
#define TIMED_SPIKE_AIR_H

#include "LevelElement/LevelElement.h"


class TimedSpikeAir : public LevelElement
{
public:
	static const char ownSym = '^';
	static const char ownKey = '8';
	static const int ownId = 9;
	static const fc::Color ownColor = RED;
	static const fc::Color disabledColor = DARK_GRAY;
	TimedSpikeAir(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	TimedSpikeAir* clone() override;
};

#endif // ! TIMED_SPIKE_AIR_H
