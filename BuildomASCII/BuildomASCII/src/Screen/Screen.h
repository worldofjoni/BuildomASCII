#pragma once
#ifndef SCREEN_H
#define SCREEN_H


class Screen
{
public:
	static const int 
		WIDTH = 100, 
		HEIGHT = 50;
	static const fc::Color
		defaultBackgroundColor = LIGHT_GRAY,
		defaultTextColor = BLUE_LIGHT;
	void printScreen();
	virtual ~Screen() {};

private:

	char content[WIDTH][HEIGHT];
};



#endif
