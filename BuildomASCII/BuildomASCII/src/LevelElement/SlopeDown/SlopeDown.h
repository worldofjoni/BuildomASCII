#pragma once
#ifndef SLOPE_DOWN_H
#define SLOPE_DOWN_H

#include "LevelElement/LevelElement.h"

class SlopeDown : public LevelElement
{
private:

public:
	SlopeDown(bool deletable);
	bool steppedOn(Pos &pos) override;
	bool steppedIn(Pos &pos) override;
	SlopeDown* clone() override;

};




#endif // !SLOPE_DOWN_H
