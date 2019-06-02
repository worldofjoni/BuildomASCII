// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Screen/Screen.h"
#include "Button/Button.h"


class StartScreen : public Screen
{
private:
	Button playButton = Button("Starten", Button::runPlayButton);
	Button customButton = Button("Eigene Level", Button::runCustomSelectButton);
	Button exitButton = Button("Verlassen", Button::runExitButton);
	Button creditsButton = Button("Abspann", Button::runCreditsButton);
	Button manualButton = Button("Hilfe", Button::runManualButton);

	static const int maxSel = 5;
	

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

public:
	
	void run();

	StartScreen();
	~StartScreen();

	StartScreen(const StartScreen& other) = delete;
	StartScreen(StartScreen&& other) = delete;
	StartScreen& operator=(const StartScreen& other) = delete;
	StartScreen& operator=(StartScreen&& other) = delete;
};

#endif