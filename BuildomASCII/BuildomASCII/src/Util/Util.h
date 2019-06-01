// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef Util_h
#define Util_h

enum Direction
{
	NONE = 0,
	UP = 3,
	DOWN = 2,
	LEFT = -1,
	RIGHT = 1,
};


struct Pos
{
	int x, y;
	Pos below();
	bool isOnLevelBorder();
	bool operator== (Pos other);
	bool operator!= (Pos other);
} 
const INVALID_POS{ -1,-1 };


char getCharLow();
void openSound();
void closeSound();
void winSound();
void deathSound();
void playMusic(const char str[]);
bool& musicAllowed();
void printMultiline(Pos pos, std::string str, int width, fc::Color textColor, fc::Color backColor);

#endif // !POS_H
