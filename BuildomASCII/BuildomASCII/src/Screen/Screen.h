// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef SCREEN_H
#define SCREEN_H

static const fc::Color _defaultTextColor = BLUE_LIGHT;
static const fc::Color _defaultBackgroundColor = LIGHT_GRAY;

struct Pixel // Struct containig all the information for each pixel
{
	char content = ' ';
	fc::Color textColor = _defaultTextColor;
	fc::Color backgroundColor = _defaultBackgroundColor;
};

class LevelElement;

class Screen
{
public:
	static const int 
		WIDTH = 100, 
		HEIGHT = 50;

	static const fc::Color
		defaultBackgroundColor = _defaultBackgroundColor,
		defaultTextColor = _defaultTextColor;

	virtual ~Screen() {};

protected:
	Pixel content[WIDTH][HEIGHT];

	void printScreen();
	void setBlank();

	// Functions to write on content
	Pos writeAt(int x, int y, char c);
	Pos writeAt(Pos pos, char c);

	Pos writeAt(int x, int y, const char str[]);
	Pos writeAt(Pos pos, const char str[]);

	Pos writeAt(int x, int y, int num);
	Pos writeAt(int x, int y, int num, unsigned int digis, fc::Color color);
	Pos writeAt(Pos pos, int num, unsigned int digis, fc::Color color);
	void writeMultiline(Pos pos, std::string str, int width, char sym[] = nullptr, fc::Color col[] = nullptr, fc::Color backCol[] = nullptr);
	void writeMultilineSyms(Pos pos, std::string str, int width, LevelElement* elements[]);
	void copyContent(Pixel old[WIDTH][HEIGHT]);

};

#endif