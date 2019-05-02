#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Screen/Screen.h"
#include "Button/PlayStoryButton/PlayStoryButton.h"
#include "Button/ExitButton/ExitButton.h"

struct Position
{
	int x = 0, y = 0;
};

class StartScreen : public Screen
{
private:

public:
	
	PlayStoryButton* playButton = new PlayStoryButton();
	ExitButton *exitButton = new ExitButton();



	void placeWord(int px, int py, Button *button);
	void run();

	StartScreen() {};
	~StartScreen();

	StartScreen(const StartScreen& other) = delete;
	StartScreen(StartScreen&& other) = delete;
	StartScreen& operator=(const StartScreen& other) = delete;
	StartScreen& operator=(StartScreen&& other) = delete;
};



#endif