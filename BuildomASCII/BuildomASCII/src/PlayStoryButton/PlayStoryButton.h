#pragma once
#ifndef PLAYSTORYBUTTON_H
#define PLAYSTORYBUTTON_H

#include "../Button/Button.h"

class PlayStoryButton : Button
{
public:
	int wordSize = 4;
	char word[wordArraySize] = "Play";

	void run();
};


#endif // !PLAYSTORYBUTTON_H
