#pragma once
#ifndef SLOPE_UP_H
#define SLOPE_UP_H

#include "LevelElement/LevelElement.h"


class SlopeUp : public LevelElement
{
private:

public:
	SlopeUp(bool deletable);
	bool steppedOn(Pos &pos) override;
	bool steppedIn(Pos &pos) override;
	SlopeUp* clone() override;

};




#endif // !SLOPE_UP_H
