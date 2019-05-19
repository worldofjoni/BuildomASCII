#include "pch/pch.h"
#include "PlayStoryButton.h"

// for build
#include "Level/Level.h"
#include "Screen/Screen.h"
#include "Screen/Build/Build.h"
#include "BdalManager/BdalManager.h"

PlayStoryButton::PlayStoryButton()
{
	word = "Starten";
	wordSize = word.length();
}

int PlayStoryButton::run()
{
	BdalManager filemanager;
	// Test


	/*
	Level level; 
	level.setStartEnd({ 50, 5 }, { 90, 30 });
	// max count of elements
	int maxElements[LevelElement::countOfElements] = { -1, -1, -1, -1, -1 , -1};
	level.setMaxElements(maxElements);
	*/



	Build build(filemanager.getLevel("1", LevelType::STORY));

	build.run();

	return 0;
}
