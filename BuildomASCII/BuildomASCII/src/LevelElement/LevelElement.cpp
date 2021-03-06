// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "LevelElement.h"

fc::Color LevelElement::getColor()
{
	return deletable ? color^0x0008 : color; // darker color if placed by user
}

void LevelElement::setColor(fc::Color col)
{
	color = col;
}
