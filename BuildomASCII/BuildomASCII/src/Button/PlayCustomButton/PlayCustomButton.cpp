#include "pch/pch.h"
#include "PlayCustomButton.h"
#include "Screen/CustomLevelSelect/CustomLevelSelect.h" // Hier hätte es doch gereicht


PlayCustomButton::PlayCustomButton()
{
	word = "Eigene Level";
	wordSize = word.length();
}

int PlayCustomButton::run()
{
	CustomLevelSelect levelSelect;
	levelSelect.run();
	

	return 0;
}
