#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Screen/Screen.h"
#include "Button/Button.h"

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
	CreditsButton* creditsButton = new CreditsButton();

	static const int maxSel = 3;
	
	



	
	void run();

	StartScreen();
	~StartScreen();

	StartScreen(const StartScreen& other) = delete;
	StartScreen(StartScreen&& other) = delete;
	StartScreen& operator=(const StartScreen& other) = delete;
	StartScreen& operator=(StartScreen&& other) = delete;
};



#endif