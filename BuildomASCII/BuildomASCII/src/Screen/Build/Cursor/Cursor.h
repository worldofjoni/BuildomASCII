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
	int x = level->start.x, y = level->start.y;
	void move(Direction dir);
	bool isVisable = true; // if cursor is visible
	char symbol = 'x';
	fc::Color color = RED_LIGHT;
};


#endif // !CURSER_H