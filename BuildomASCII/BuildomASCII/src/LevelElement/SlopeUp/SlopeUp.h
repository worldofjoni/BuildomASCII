#pragma once
#ifndef SLOPE_UP_H
#define SLOPE_UP_H

#include "LevelElement/LevelElement.h"


class SlopeUp : public LevelElement
{
private:

public:
	SlopeUp();
	void steppedOn() override;
	void steppedIn() override;
	SlopeUp* clone() override;

};




#endif // !SLOPE_UP_H
