#include "pch/pch.h"
#include "ChangeDir.h"

ChangeDir::ChangeDir(bool deletable)
{
	id = 4;
	symbol = 29;
	this->deletable = deletable;
	color = YELLOW_LIGHT;
}



void ChangeDir::steppedOn(Build* build)
{

}

void ChangeDir::steppedIn(Build* build)
{
	if (build->playerDirection == RIGHT) { build->playerDirection = LEFT; }
	else { build->playerDirection = RIGHT; }

}

ChangeDir* ChangeDir::clone()
{
	return (new ChangeDir(*this));
}
