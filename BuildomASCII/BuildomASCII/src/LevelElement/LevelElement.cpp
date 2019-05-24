#include "pch/pch.h"
#include "LevelElement.h"

fc::Color LevelElement::getColor()
{
	return deletable ? color^0x0008 : color;
}

void LevelElement::setColor(fc::Color col)
{
	color = col;
}
