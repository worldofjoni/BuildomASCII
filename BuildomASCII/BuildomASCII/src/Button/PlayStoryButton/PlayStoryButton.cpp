#include "pch/pch.h"
#include "PlayStoryButton.h"

// for build
#include "Level/Level.h"
#include "Screen/Screen.h"
#include "Screen/Build/Build.h"

PlayStoryButton::PlayStoryButton()
{
	wordSize = 4;
	word = "Play";
}

int PlayStoryButton::run()
{
	// Test

	Level level(Screen::WIDTH - 2, Screen::HEIGHT - 10); // Space for Frame and menu bar
	level.setStartEnd({ 50, 5 }, { 90, 30 });
	// max count of elements
	int maxElements[LevelElement::countOfElements] = { -1, -1, -1, -1, -1 };
	level.setMaxElements(maxElements);

	Build build(level);

	build.run();

	return 0;
}
