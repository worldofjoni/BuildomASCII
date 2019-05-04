#pragma once
#ifndef CURSER_H
#define CURSER_H

#include "Screen/Build/Build.h"
#include "pch/pch.h"

enum Direction
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

class Cursor
{
private:
	Level * level;
public:
	Cursor(Level* level);
	int x = 0, y = 0;
	void move(Direction dir);
	bool isVisable = true; // if cursor is visible
	char symbol = 'x';
	fc::Color color = RED_LIGHT;
};


#endif // !CURSER_H