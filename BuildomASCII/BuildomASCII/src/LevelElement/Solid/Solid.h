#pragma once
#ifndef SOLID_H
#define SOLID_H

#include "LevelElement/LevelElement.h"

class Solid : public LevelElement
{
private:
public:
	static const char ownSym = 219;
	static const char ownKey = ' ';
	Solid(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	Solid* clone() override;
	
};







#endif // !SOLID_H