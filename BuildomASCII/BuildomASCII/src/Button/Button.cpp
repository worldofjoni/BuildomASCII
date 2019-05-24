#include "pch/pch.h"
#include "Button.h"

#include "BdalManager/BdalManager.h"
#include "Screen/CustomLevelSelect/CustomLevelSelect.h"
#include "Screen/Credits/Credits.h"
#include "Screen/Manual/Manual.h"
#include "Screen/LevelEditor/LevelEditor.h"

Button::Button(const char str[], int(*run)())
	:run(run), name(str)
{
}


int Button::runPlayButton()
{
	BdalManager filemanager;
	Build build(filemanager.getLevel("1", LevelType::STORY));

	build.run();

	return 0;
}

int Button::runCustomSelectButton()
{
	CustomLevelSelect levelSelect;
	levelSelect.run();

	return 0;
}


int Button::runExitButton()
{
	fc::clearScreen(BLACK);
	return 1;
}

int Button::runCreditsButton()
{
	Credits credits;
	credits.run();

	return 0;
}

int Button::runManualButton()
{
	Manual manual;
	manual.run();
	return 0;
}

int Button::runCreateCustomButton()
{
	// Level Editor

	LevelEditor levelEditor;
	levelEditor.run();
	return 0;
}

