#include "pch/pch.h"
#include "PlayCustomButton.h"


PlayCustomButton::PlayCustomButton()
{
	word = "Custom Level";
	wordSize = word.length();
}

int PlayCustomButton::run()
{
	CustomLevelSelect levelSelect;
	levelSelect.run();
	

	return 0;
}
