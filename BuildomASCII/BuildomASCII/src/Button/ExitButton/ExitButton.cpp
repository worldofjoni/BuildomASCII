#include "pch/pch.h"
#include "ExitButton.h"


ExitButton::ExitButton()
{
	wordSize = 4;
	word = "Exit";
}

int ExitButton::run()
{
	fc::clearScreen(BLACK);
	return 1;
}
