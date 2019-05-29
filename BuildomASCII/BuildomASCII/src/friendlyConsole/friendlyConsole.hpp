// #################################################################
// #    Library to easily change console colours and much more     #
// #                      © Jonatan Ziegler                        #
// #################################################################



#pragma once
#ifndef _FRIENDLY_CONSOLE_
#define _FRIENDLY_CONSOLE

#pragma comment(lib, "Winmm.lib")
#include <ostream>
typedef wchar_t WCHAR;

#define gotoxy fc::setCursorPos
#define getrandom_int fc::getRandom
#define wait fc::waitMs

// defines diffrent colors
#define BLACK 0x0000
#define BLUE_DARK 0x0001
#define GREEN_DARK 0x0002
#define CYAN_DARK 0x0003
#define RED_DARK 0x0004
#define MAGENTA_DARK 0x0005
#define YELLOW_DARK 0x0006
#define LIGHT_GRAY 0x0007
#define DARK_GRAY 0x0008
#define BLUE 0x0009
#define GREEN 0x000A
#define CYAN 0x000B
#define RED 0x000C
#define MAGENTA 0x000D
#define YELLOW 0x000E
#define WHITE 0x000F

// old colors
#define BLUE_LIGHT BLUE_DARK
#define GREEN_LIGHT GREEN_DARK
#define CYAN_LIGHT CYAN_DARK
#define RED_LIGHT RED_DARK
#define MAGENTA_LIGHT MAGENTA_DARK
#define YELLOW_LIGHT YELLOW_DARK


// defines diffrent Tones
#define NOTE_C 	523
#define NOTE_D 	587
#define NOTE_E 	659
#define NOTE_F 	698
#define NOTE_G 	784
#define NOTE_A 	880
#define NOTE_B 	988
#define NOTE_H 	NOTE_B // for german note

// different fonts
#define F_RASTERFONT L"Terminal"
#define F_CONSOLAS L"Consolas"
#define F_COURIER_NEW L"Courier New"
#define F_LUCIDA_CONSOLE L"Lucida Console"
#define F_MS_GOTHIC L"MS Gothic"
#define F_N_SIM_SUN L"NSimSun"
#define F_SIM_SUN_EXT_B L"SimSun-ExtB"


namespace fc {


	// abbr. for unsigned short
	typedef unsigned short Color;

	// functions and structs for cout integration
	
	enum Action
	{
		COLOR = 1,
		BACK_COLOR = 2,
	};

	struct Cmd
	{
		Action action;
		Color value;
	};
	
	Cmd color(Color color);
	Cmd backColor(Color color);
	std::ostream& operator<<(std::ostream& os, Cmd cmd);

	// function prototypes
	void setTextColor(Color color);
	void setBackgroundColor(Color color);
	void clearScreen();
	void clearScreen(Color color);
	void setTitle(const char name[]);
	void setCursorPos(int x, int y);
	void getCursorPosition(int& x, int& y);
	void hideCursor();
	void showCursor();
	void setWindowSizePX(int width, int height); //size in Pixel (shouldn't use)
	void setWindowSize(int width, int height, bool disableScrolling = true);	//Size in characters (when Font=Rasterschrift; FontSize=8x8)
	void setWindowPos(int x, int y);
	int getRandom(int min, int max);
	void waitMs(int ms);
	void waitMsWithInterupt(int ms, bool(*func)());
	void beep(int freq, int duration = 300);
	void playSound(const char file[]);
	void playSoundRepeat(const char file[]);
	void playSoundWait(const char file[]);
	void stopSound();
	std::string getPath();
	void openExplorer(const char path[]);
	void openExplorer(std::string path);
	void openBrowser(const char url[]);
	void openBrowser(std::string url);
	bool isKeyPressed(int vKey);
	bool isKeyPressed(char key);
	void getFontSize(int& x, int& y);
	bool setFont(const wchar_t font[32]);
	bool setFontSize(int width, int height = 0); // height oly for raster-font, for each other use only width as size
	bool setBold(bool bold);
}

#endif // !_FRIENDLY_CONSOLE_