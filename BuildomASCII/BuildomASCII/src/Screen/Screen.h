#pragma once
#ifndef SCREEN_H
#define SCREEN_H


class Screen
{
public:
	
	static const int 
		WIDTH = 50, 
		HEIGHT = 100;
	static const fc::Color
		defaultBackgroundColor = LIGHT_GRAY,
		defaultTextColor = BLUE_LIGHT;
	void printScreen();
	void setBlank();
	virtual ~Screen() {};

protected:
	char content[WIDTH][HEIGHT];

private:

};



#endif