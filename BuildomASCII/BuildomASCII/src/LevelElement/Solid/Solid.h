#pragma once
#ifndef SOLID_H
#define SOLID_H

#include "LevelElement/LevelElement.h"

class Solid : public LevelElement
{
private:

public:
	Solid(bool deletable);
	bool steppedOn(Pos &pos) override;
	bool steppedIn(Pos &pos) override;
	Solid* clone() override;
	
};







#endif // !SOLID_H