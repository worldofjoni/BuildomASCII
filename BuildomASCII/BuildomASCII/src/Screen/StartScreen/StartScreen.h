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
	

	const int LOGO_WIDTH = 77, LOGO_HEIGHT = 6;
	const char logo[6][77] =
	{
		R"( ____        _ _     _                             _____  _____ _____ _____ )",
		R"(|  _ \      (_) |   | |                     /\    / ____|/ ____|_   _|_   _|)",
		R"(| |_) |_   _ _| | __| | ___  _ __ ___      /  \  | (___ | |      | |   | |  )",
		R"(|  _ <| | | | | |/ _` |/ _ \| '_ ` _ \    / /\ \  \___ \| |      | |   | |  )",
		R"(| |_) | |_| | | | (_| | (_) | | | | | |  / ____ \ ____) | |____ _| |_ _| |_ )",
		R"(|____/ \__,_|_|_|\__,_|\___/|_| |_| |_| /_/    \_\_____/ \_____|_____|_____|)"

	};



	
	void run();

	StartScreen();
	~StartScreen();

	StartScreen(const StartScreen& other) = delete;
	StartScreen(StartScreen&& other) = delete;
	StartScreen& operator=(const StartScreen& other) = delete;
	StartScreen& operator=(StartScreen&& other) = delete;
};



#endif