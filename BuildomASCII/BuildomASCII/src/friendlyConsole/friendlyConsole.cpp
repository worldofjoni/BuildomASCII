// #################################################################
// #    Library to easily change console colours and much more     #
// #                      © Jonatan Ziegler                        #
// #################################################################


#pragma once
#include <Windows.h>
#include "friendlyConsole.hpp"
#include <random>
#include <chrono>



namespace fc {


	// declares used variables
	static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static HWND hWindow = GetConsoleWindow();


	//functions and structs for cout integration
	// use in ostream to set color
	Cmd color(Color color)
	{
		return { COLOR, color };
	}

	// use in ostream to set Backgroundcolor
	Cmd backColor(Color color)
	{
		return { BACK_COLOR, color };
	}

	// overloaded Operator for in ostram controll
	std::ostream& operator<<(std::ostream& os, Cmd cmd)
	{
		switch (cmd.action)
		{
		case COLOR:
			fc::setTextColor(cmd.value);
			break;
		case BACK_COLOR:
			fc::setBackgroundColor(cmd.value);
			break;
		}
		return os;
	}


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

	// sets the actual cursor position (equivilent to gotoxy)
	void setCursorPos(int x, int y)
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

	// returns a random Value
	int getRandom(int min, int max)
	{
		
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
		dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng);
		return dist6(rng);
		
	}


	// waits a specific amount of time
	void waitMs(int ms)
	{
		auto t1 = std::chrono::system_clock::now();
		while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - t1).count() < ms);
	}

	// waits a specific amout of time or until functionreturns true
	void waitMsWithInterupt(int ms, bool(*func)())
	{
		auto t1 = std::chrono::system_clock::now();
		while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - t1).count() < ms)
		{
			if (func()) return;
		}
	}

	// overrides the given variables with the actual cursor Position
	void getCursorPosition(int& x, int& y)
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hStdOut, &info);
		x = info.dwCursorPosition.X;
		y = info.dwCursorPosition.Y;
	}

	// Hides Cursor
	void hideCursor()
	{
		CONSOLE_CURSOR_INFO info;
		GetConsoleCursorInfo(hStdOut, &info);
		info.bVisible = false;
		SetConsoleCursorInfo(hStdOut, &info);
		
	}

	// Shows Cursor
	void showCursor()
	{
		CONSOLE_CURSOR_INFO info;
		GetConsoleCursorInfo(hStdOut, &info);
		info.bVisible = true;
		SetConsoleCursorInfo(hStdOut, &info);
		
	}

	// beeps with Note as freq, default duration 300
	void beep(int freq, int duration)
	{
		Beep(freq, duration);
	}


	// plays file at relative path
	void playSound(const char file[])
	{
		PlaySoundA(file, NULL, SND_ASYNC);
	}

	// same as playSound, but repeats until stopSound
	void playSoundRepeat(const char file[])
	{
		PlaySoundA(file, NULL, SND_ASYNC | SND_LOOP);
	}

	// same as playSound, but returns not until sound finished
	void playSoundWait(const char file[])
	{
		PlaySoundA(file, NULL, SND_SYNC);
	}

	// stops playing sound
	void stopSound()
	{
		PlaySoundA(NULL, NULL, NULL);
	}

	// returns current path, Note: in VS *Debugger* this is NOT the .exe path!
	std::string getPath()
	{
		char* pszFileName = NULL;
		char path[200];
		GetFullPathNameA(".", 200, path, &pszFileName);
		return std::string(path);
	}


	// opens file explorer at path
	void openExplorer(const char path[])
	{
		ShellExecuteA(NULL, "explore", path, NULL, NULL, SW_SHOWDEFAULT);
	}

	void openExplorer(std::string path)
	{
		openExplorer(path.c_str());
	}

	// opens default browser at url
	void openBrowser(const char url[])
	{
		ShellExecuteA(NULL, "open", url, NULL, NULL, SW_SHOWDEFAULT);
	}

	void openBrowser(std::string url)
	{
		openBrowser(url.c_str());
	}





}