#include "pch/pch.h"
#include "Star.h"

Star::Star(bool deletable)
{
	id = 6;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = YELLOW_LIGHT;
	fallable = true;
}



void Star::steppedOn(Build* build)
{
	
}

void Star::steppedIn(Build* build)
{
	build->stars++;
	
}

Star* Star::clone()
{
	return (new Star(*this));
}
