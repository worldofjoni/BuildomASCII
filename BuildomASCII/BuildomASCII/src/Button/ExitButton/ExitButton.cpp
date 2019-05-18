#include "pch/pch.h"
#include "ExitButton.h"


ExitButton::ExitButton()
{
	word = "Verlassen";
	wordSize = word.length();
}

int ExitButton::run()
{
	fc::clearScreen(BLACK);
	return 1;
}
