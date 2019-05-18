#include "pch/pch.h"
#include "PlayCustomButton.h"

// for LevelEditor
#include "Screen/LevelEditor/LevelEditor.h"


PlayCustomButton::PlayCustomButton()
{
	word = "Eigene Level";
	wordSize = word.length();
}

int PlayCustomButton::run()
{
	// Level Editor
	
	LevelEditor levelEditor;
	levelEditor.run();
	

	return 0;
}
