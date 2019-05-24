#pragma once
#ifndef Util_h
#define Util_h

struct Pos
{
	int x, y;
	Pos below();
	bool isOnLevelBorder();
};


char getCharLow();

#endif // !POS_H
