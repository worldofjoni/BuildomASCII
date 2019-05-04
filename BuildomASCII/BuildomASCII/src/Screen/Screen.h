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

protected:
	Pixel content[WIDTH][HEIGHT];

};



#endif