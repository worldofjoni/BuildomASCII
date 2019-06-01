// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Button.h"

#include "BdalManager/BdalManager.h"
#include "Screen/CustomLevelSelect/CustomLevelSelect.h"
#include "Screen/Credits/Credits.h"
#include "Screen/Manual/Manual.h"
#include "Screen/LevelEditor/LevelEditor.h"
#include "Screen/StorySelect/StorySelect.h"

Button::Button(const char str[], int(*run)())
	:run(run), name(str)
{
}


int Button::runPlayButton()	// Enters story select
{
	openSound();
	StorySelect storySelectScreen;
	storySelectScreen.run();

	return 0;
}

int Button::runCustomSelectButton()	// Enters custom-slevel-select
{
	openSound();
	CustomLevelSelect levelSelect;
	levelSelect.run();

	return 0;
}


int Button::runExitButton()	// Exits game
{
	closeSound();
	fc::clearScreen(BLACK);

	return 1;
}

int Button::runCreditsButton()	// Enters credits
{
	openSound();
	Credits credits;
	credits.run();

	return 0;
}

int Button::runManualButton()	// Enters manual
{
	openSound();
	Manual manual;
	manual.run();

	return 0;
}

int Button::runCreateCustomButton()	// Enters level-creation
{
	openSound();
	LevelEditor levelEditor;
	levelEditor.run();

	return 0;
}

