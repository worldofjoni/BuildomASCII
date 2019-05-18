#include "pch/pch.h"
#include "PlayStoryButton.h"

// for build
#include "Level/Level.h"
#include "Screen/Screen.h"
#include "Screen/Build/Build.h"

PlayStoryButton::PlayStoryButton()
{
	word = "Starten";
	wordSize = word.length();
}

int PlayStoryButton::run()
{
	// Test

	Level level; 
	level.setStartEnd({ 50, 5 }, { 90, 30 });
	// max count of elements
	int maxElements[LevelElement::countOfElements] = { -1, -1, -1, -1, -1 , -1};
	level.setMaxElements(maxElements);

	Build build(level);

	build.run();

	return 0;
}
