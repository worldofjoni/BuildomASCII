#pragma once
#ifndef SPIKE_H
#define SPIKE_H

#include "LevelElement/LevelElement.h"

class Spike : public LevelElement
{
public:
	Spike(bool deletable);
	void steppedOn(Build* build) override;
	void steppedIn(Build* build) override;
	Spike* clone() override;
};


#endif // !SPIKE_H
