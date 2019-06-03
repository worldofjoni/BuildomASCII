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


int Button::runPlayButton()
{
	openSound();
	StorySelect storySelectScreen;
	storySelectScreen.run();
	return 0;


	/*BdalManager filemanager;
	Build build(filemanager.getLevel("1", LevelType::STORY));*/

	//build.run();

	return 0;
}

int Button::runCustomSelectButton()
{
	openSound();
	CustomLevelSelect levelSelect;
	levelSelect.run();

	return 0;
}


int Button::runExitButton()
{
	closeSound();
	fc::clearScreen(BLACK);
	return 1;
}

int Button::runCreditsButton()
{
	openSound();
	Credits credits;
	credits.run();

	return 0;
}

int Button::runManualButton()
{
	openSound();
	Manual manual;
	manual.run();
	return 0;
}

int Button::runCreateCustomButton()
{
	openSound();
	// Level Editor

	LevelEditor levelEditor;
	levelEditor.run();
	fc::stopSound();
	fc::playSoundRepeat("music/music.wav");
	return 0;
}

