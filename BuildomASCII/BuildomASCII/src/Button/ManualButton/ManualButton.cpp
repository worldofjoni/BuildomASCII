#include "pch/pch.h"
#include "ManualButton.h"

#include "Screen/Manual/Manual.h"

ManualButton::ManualButton()
{
	word = "Hilfe";
	wordSize = word.length();
}

int ManualButton::run()
{
	Manual manual;
	manual.run();

	return 0;
}
