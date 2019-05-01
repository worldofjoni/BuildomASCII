#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "../Screen/Screen.h"


class StartScreen : public Screen
{
private:

public:
	
	static const int wordArraySize = 10;
	int selection = 0;
	void run();

	void placeWord(int px, int py, char word[wordArraySize]);
};



#endif