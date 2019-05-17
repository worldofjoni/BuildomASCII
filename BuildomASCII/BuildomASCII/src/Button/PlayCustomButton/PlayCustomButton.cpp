#include "pch/pch.h"
#include "PlayCustomButton.h"

// for LevelEditor
#include "Screen/LevelEditor/LevelEditor.h"


PlayCustomButton::PlayCustomButton()
{
	word = "Custom Level";
	wordSize = word.length();
}

int PlayCustomButton::run()
{
	// Level Editor
	
	LevelEditor levelEditor;
	levelEditor.run();
	

	return 0;
}
