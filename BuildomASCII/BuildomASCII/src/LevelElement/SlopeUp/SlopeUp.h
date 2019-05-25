#pragma once
#ifndef SLOPE_UP_H
#define SLOPE_UP_H

#include "LevelElement/LevelElement.h"


class SlopeUp : public LevelElement
{
private:
public:
	static const char ownSym = '/';
	static const char ownKey = '1';
	static const int ownId = 2;
	SlopeUp(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	SlopeUp* clone() override;

};




#endif // !SLOPE_UP_H
