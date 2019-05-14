#include "pch/pch.h"
#include "Spike.h"

Spike::Spike(bool deletable)
{
	id = 5;
	symbol = 30; 
	this->deletable = deletable;
	color = BLACK;
	fallable = false;
}



void Spike::steppedOn(Build* build)
{
	build->playerGameOver = true;
}

void Spike::steppedIn(Build* build)
{
	build->playerGameOver = true;

}

Spike* Spike::clone()
{
	return (new Spike(*this));
}
