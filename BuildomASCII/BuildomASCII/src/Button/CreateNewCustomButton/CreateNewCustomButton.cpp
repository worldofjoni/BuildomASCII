#include "pch/pch.h"
#include "CreateNewCustomButtom.h"

// for LevelEditor
#include "Screen/LevelEditor/LevelEditor.h"


CreateNewCustomButton::CreateNewCustomButton()
{
	word = "NEW";
	wordSize = word.length();
}

int CreateNewCustomButton::run()
{
	// Level Editor

	LevelEditor levelEditor;
	levelEditor.run();


	return 0;
}
