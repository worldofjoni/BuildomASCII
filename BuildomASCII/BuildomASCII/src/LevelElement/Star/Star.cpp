#include "pch/pch.h"
#include "Star.h"

Star::Star(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = YELLOW;
	fallable = true;
}



void Star::steppedOn(Build* build)
{
	
}

void Star::steppedIn(Build* build)
{
	if (this->symbol == ownSym)
	{
		build->stars++;
		this->symbol = Empty::ownSym;
		fc::beep(NOTE_H, 50);

	}
	
}

Star* Star::clone()
{
	return (new Star(*this));
}
