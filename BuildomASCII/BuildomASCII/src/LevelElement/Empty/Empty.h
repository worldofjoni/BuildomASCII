#pragma once
#ifndef EMPTY_H
#define EMPTY_H

#include "LevelElement/LevelElement.h"

class Empty : public LevelElement
{
private:

public:
	Empty(bool deletable);
	void steppedOn(Build *build) override;
	void steppedIn(Build *build) override;
	Empty* clone() override;
	
};







#endif // !EMPTY_H