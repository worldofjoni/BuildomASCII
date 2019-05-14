#pragma once
#ifndef SLOPE_UP_H
#define SLOPE_UP_H

#include "LevelElement/LevelElement.h"


class SlopeUp : public LevelElement
{
private:

public:
	SlopeUp(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	SlopeUp* clone() override;

};




#endif // !SLOPE_UP_H
