// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "LevelElement/LevelElement.h"

class Zombie : public LevelElement
{
private:
public:
	Pos pos;
	Pos formPos;
	Direction dir = Direction::RIGHT;
	static const char ownSym = 2;
	static const char ownKey = '9';
	static const int ownId = 10;
	Zombie(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	Zombie* clone() override;
	void move(Build* build);
	void reset(Build* build);
};


#endif // ! STAR_H
