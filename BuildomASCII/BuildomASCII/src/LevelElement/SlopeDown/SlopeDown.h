#pragma once
#ifndef SLOPE_DOWN_H
#define SLOPE_DOWN_H

#include "LevelElement/LevelElement.h"

class SlopeDown : public LevelElement
{
private:

public:
	SlopeDown(bool deletable);
	void steppedOn() override;
	void steppedIn() override;
	SlopeDown* clone() override;

};




#endif // !SLOPE_DOWN_H
