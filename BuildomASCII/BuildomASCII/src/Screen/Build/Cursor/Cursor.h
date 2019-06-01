// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef CURSER_H
#define CURSER_H

#include "Screen/Build/Build.h"
#include "pch/pch.h"


class Cursor
{
private:
	Level * level;
public:
	Cursor(Level* level);
	Pos pos;
	Direction dir = NONE;
	void move();
	bool isVisible = true; // if cursor is visible
	char symbol = 'x';
	fc::Color color = RED_LIGHT;
};


#endif // !CURSER_H