
#pragma once
#include "pch/pch.h"
#include <Windows.h>
#include "friendlyConsole.hpp"
#include <random>



namespace fc {


	// declares used variables
	static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static HWND hWindow = GetConsoleWindow();




	// function to set text color
	void setTextColor(Color color)
	{
		Color data;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hStdOut, &info);			// gets current coler
		data = (info.wAttributes & 0xFFF0) | color;			// adds wanted color
		SetConsoleTextAttribute(hStdOut, data);				// changes new color
	}

	// function to set backgroundcolor
	void setBackgroundColor(Color color)
	{
		Color data;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hStdOut, &info);			// gets current coler
		data = (info.wAttributes & 0xFF0F) | (color << 4);	// adds wanted color
		SetConsoleTextAttribute(hStdOut, data);				// changes new color
	}

	// function that clears the screen
	inline void clearScreen()
	{
		system("cls");
	}

	// function taht clears the screen and sets it to a color
	void clearScreen(Color color) {
		setBackgroundColor(color);
		clearScreen();
	}


	// sets the console title
	void setTitle(const char name[])
	{
		SetConsoleTitleA(name);
	}

	// sets the actual curser position (equivilent to gotoxy)
	void setCurserPos(int x, int y)
	{
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hStdOut, pos);
	}

	// sets the size of the window in pixel
	void setWindowSizePX(int with, int height)
	{
		RECT r;
		GetWindowRect(hWindow, &r);
		MoveWindow(hWindow, r.left, r.top, with, height, false);
	}

	// sets the size of the window in chars
	void setWindowSize(int with, int height)
	{
		with = (with * 40 + 184)/5;
		height = (height * 40 + 212)/5;
		setWindowSizePX(with, height);
	}

	// sets the pos of the window
	void setWindowPos(int x, int y)
	{
		RECT r;
		GetWindowRect(hWindow, &r);
		MoveWindow(hWindow, x, y, r.right - r.left, r.bottom - r.top, false);
	}

	// sets te size of each character (in pixels)
	void setFontSize(int with, int height)
	{
		CONSOLE_FONT_INFOEX info;
		info.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(hStdOut, true, &info);
		info.dwFontSize.Y = height;
		info.dwFontSize.X = with;
		SetCurrentConsoleFontEx(hStdOut, false, &info);
	}

	int getRandom(int min, int max)
	{
		
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
		dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng);
		return dist6(rng);
		
	}






}