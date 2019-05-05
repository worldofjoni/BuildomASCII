#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "friendlyConsole/friendlyConsole.hpp"

static const fc::Color _defaultTextColor = BLUE_LIGHT;
static const fc::Color _defaultBackgroundColor = LIGHT_GRAY;

struct Pixel // Struct containig all the information for each pixel
{
	char content = ' ';
	fc::Color textColor = _defaultTextColor;
	fc::Color backgroundColor = _defaultBackgroundColor;

};

struct Pos
{
	int x, y;
};

class Screen
{
public:
	static const int 
		WIDTH = 100, 
		HEIGHT = 50;
	static const fc::Color
		defaultBackgroundColor = _defaultBackgroundColor,
		defaultTextColor = _defaultTextColor;
	void printScreen();



	virtual ~Screen() {};


	// Functions to write on content
	Pos writeAt(int x, int y, char c);
	Pos writeAt(Pos pos, char c);

	Pos writeAt(int x, int y, const char str[]);
	Pos writeAt(Pos pos, const char str[]);

	Pos writeAt(int x, int y, int num);
	Pos writeAt(int x, int y, int num, unsigned int digis);
	Pos writeAt(Pos pos, int num, unsigned int digis);

protected:
	Pixel content[WIDTH][HEIGHT];

};



#endif