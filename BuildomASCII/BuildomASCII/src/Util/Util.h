#pragma once
#ifndef Util_h
#define Util_h



struct Pos
{
	int x, y;
	Pos below();
	bool isOnLevelBorder();
	bool operator== (Pos other);
	bool operator!= (Pos other);
} const INVALID_POS{ -1,-1 };


char getCharLow();

#endif // !POS_H
