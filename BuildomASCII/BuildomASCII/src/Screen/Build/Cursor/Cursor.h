// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef CURSER_H
#define CURSER_H

#include "Level/Level.h"
#include "pch/pch.h"


class Cursor
{
private:
	Level* level;
public:
	Cursor(Level* level);
	void move();
	Pos pos;
	Direction dir = NONE;
	bool isVisible = true;
	char symbol = 'x';
	fc::Color color = RED_LIGHT;
};


#endif // !CURSER_H