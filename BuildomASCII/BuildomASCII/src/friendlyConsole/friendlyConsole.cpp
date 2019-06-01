// #################################################################
// #    Library to easily change console colours and much more     #
// #                     by Jonatan Ziegler                        #
// #################################################################

#pragma once
#include "friendlyConsole.hpp"
#include <Windows.h>
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
	void setWindowSizePX(int width, int height)
	{
		RECT r;
		GetWindowRect(hWindow, &r);
		MoveWindow(hWindow, r.left, r.top, width, height, false);
	}

	// sets the size of the window in chars (and disables Scrolling)
	void setWindowSize(int width, int height, bool disableScrolling)
	{
		if (disableScrolling)
		{
			int width_ = (width * 8 + 40);
			int height_ = (height * 8 + 40);
			setWindowSizePX(width_, height_);

			COORD coord;
			coord.X = width;
			coord.Y = height;
			SetConsoleScreenBufferSize(hStdOut, coord);
		}
		else
		{
			width = (width * 40 + 184)/5;
			height = (height * 40 + 212)/5;
			setWindowSizePX(width, height);
		}
	}

	// sets the pos of the window
	void setWindowPos(int x, int y)
	{
		RECT r;
		GetWindowRect(hWindow, &r);
		MoveWindow(hWindow, x, y, r.right - r.left, r.bottom - r.top, false);
	}

	// returns a random Value
	int getRandom(int min, int max)
	{
		if (min > max)
		{
			int i = min;
			min = max;
			max = i;
		}
		int diff = max - min;
		
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, diff);
		dist(rng); dist(rng); dist(rng); dist(rng); dist(rng); dist(rng); dist(rng); dist(rng);
		return dist(rng) + min;
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

	// overrides the given variables width the actual cursor Position
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

	// beeps width Note as freq, default duration 300
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

	bool isKeyPressed(int key)
	{
		short s = GetKeyState(key);
		return (s & (1 << sizeof(short) * 8));
	}

	bool isKeyPressed(char vKey)
	{
		int _key = VkKeyScanExA(vKey, LoadKeyboardLayoutA("0000080", NULL));
		_key &= 0x00FF;

		// if is Key is Number (0-9) also convert to NumpadKey
		int key_alt = _key;
		if (key_alt >> 4 == 0x3)
		{
			key_alt &= 0x0F;
			key_alt |= 0x60;
			if (isKeyPressed(key_alt)) return true;
		}

		return isKeyPressed(_key);
	}

	void getFontSize(int& x, int& y)
	{
		CONSOLE_FONT_INFO info;
		bool b = GetCurrentConsoleFont(hStdOut, false, &info);
		COORD c = GetConsoleFontSize(hStdOut, info.nFont);
		x = c.X;
		y = c.Y;
	}

	bool setFont(const wchar_t font[32])
	{
		CONSOLE_FONT_INFOEX info;
		info.cbSize = sizeof(info);
		if (!GetCurrentConsoleFontEx(hStdOut, false, &info)) return false;

		info.FontFamily = wcscmp(font, L"Terminal") == 0 ? 48 : 54;

		for (int i = 0; i < 32; i++) info.FaceName[i] = font[i];
	
		if (!SetCurrentConsoleFontEx(hStdOut, false, &info)) return false;

		return true;
	}

	bool setFontSize(int width, int height)
	{
		CONSOLE_FONT_INFOEX info;
		info.cbSize = sizeof(info);
		if (!GetCurrentConsoleFontEx(hStdOut, false, &info)) return false;

		if (height == 0) // for only a size
		{
			info.dwFontSize.Y = width;
		}
		else // for width and height
		{
			info.dwFontSize.X = width;
			info.dwFontSize.Y = height;
		}

		if (!SetCurrentConsoleFontEx(hStdOut, false, &info)) return false;

		return true;
	}

	bool setBold(bool bold)
	{
		CONSOLE_FONT_INFOEX info;
		info.cbSize = sizeof(info);
		if (!GetCurrentConsoleFontEx(hStdOut, false, &info)) return false;

		info.FontWeight = bold ? 700 : 400;

		if (!SetCurrentConsoleFontEx(hStdOut, false, &info)) return false;

		return true;
	}

}
