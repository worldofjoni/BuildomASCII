#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "../Screen/Screen.h"
#include "../Button/Button.h"
#include "../PlayStoryButton/PlayStoryButton.h"


class StartScreen : Screen
{
private:

public:
	
	PlayStoryButton* playButton = new PlayStoryButton();
	void placeWord(int px, int py, char word[Button::wordArraySize], int wordSize);
	void run();

};



#endif