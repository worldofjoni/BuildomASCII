#include "pch/pch.h"
#include "ChangeDir.h"

ChangeDir::ChangeDir(bool deletable)
{
	id = 4;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = YELLOW_LIGHT;
	fallable = true;
}



void ChangeDir::steppedOn(Build* build)
{

}

void ChangeDir::steppedIn(Build* build)
{
	if (build->playerDirection == RIGHT)  
		build->playerDirection = LEFT; 
	else { build->playerDirection = RIGHT; }

}

ChangeDir* ChangeDir::clone()
{
	return (new ChangeDir(*this));
}
