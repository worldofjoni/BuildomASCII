// #################################################################
// #    Library to easily change console colours and much more     #
// #                      © Jonatan Ziegler                        #
// #################################################################



#pragma once
#ifndef _FRIENDLY_CONSOLE_
#define _FRIENDLY_CONSOLE

#pragma comment(lib, "Winmm.lib")
#include <ostream>

#define gotoxy fc::setCursorPos
#define getrandom_int fc::getRandom
#define wait fc::waitMs

// defines diffrent colors
#define BLACK 0x0000
#define BLUE_LIGHT 0x0001
#define GREEN_LIGHT 0x0002
#define CYAN_LIGHT 0x0003
#define RED_LIGHT 0x0004
#define MAGENTA_LIGHT 0x0005
#define YELLOW_LIGHT 0x0006
#define LIGHT_GRAY 0x0007
#define DARK_GRAY 0x0008
#define BLUE 0x0009
#define GREEN 0x000A
#define CYAN 0x000B
#define RED 0x000C
#define MAGENTA 0x000D
#define YELLOW 0x000E
#define WHITE 0x000F

// defines diffrent Tones
#define NOTE_C 	523
#define NOTE_D 	587
#define NOTE_E 	659
#define NOTE_F 	698
#define NOTE_G 	784
#define NOTE_A 	880
#define NOTE_B 	988
#define NOTE_H 	NOTE_B // for german note


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
	inline void clearScreen();
	void clearScreen(Color color);
	void setTitle(const char name[]);
	void setCursorPos(int x, int y);
	void setWindowSizePX(int with, int height); //size in Pixel (shouldn't use)
	void setWindowSize(int with, int height);	//Size in characters (when Font=Rasterschrift; FontSize=8x8)
	void setWindowPos(int x, int y);
	void setFontSize(int with, int height = 0); // experimental
	int getRandom(int min, int max);
	void waitMs(int ms);
	void waitMsWithInterupt(int ms, bool(*func)());
	void getCursorPosition(int& x, int& y);
	void hideCursor();
	void showCursor();
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

}

#endif // !_FRIENDLY_CONSOLE_