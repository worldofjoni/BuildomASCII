#pragma once
#ifndef EMPTY_H
#define EMPTY_H

#include "LevelElement/LevelElement.h"

class Empty : public LevelElement
{
private:

public:
	Empty(bool deletable);
	bool steppedOn(Pos &pos) override;
	bool steppedIn(Pos &pos) override;
	Empty* clone() override;
	
};







#endif // !EMPTY_H