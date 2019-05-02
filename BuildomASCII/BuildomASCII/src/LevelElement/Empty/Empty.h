#pragma once
#ifndef EMPTY_H
#define EMPTY_H

#include "LevelElement/LevelElement.h"

class Empty : public LevelElement
{
private:

public:
	Empty();
	void steppedOn() override;
	void steppedIn() override;
	Empty* clone() override;
	
};







#endif // !EMPTY_H