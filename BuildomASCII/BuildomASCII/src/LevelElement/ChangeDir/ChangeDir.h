#pragma once
#ifndef CHANGEDIR_H
#define CHANGEDIR_H

#include "LevelElement/LevelElement.h"

class ChangeDir : public LevelElement
{
public:
	ChangeDir(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	ChangeDir* clone() override;
};

#endif // !CHANGEDIR_H
