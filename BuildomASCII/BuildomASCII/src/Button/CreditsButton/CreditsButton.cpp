#include "pch/pch.h"
#include "CreditsButton.h"
#include "Screen/Credits/Credits.h"

CreditsButton::CreditsButton()
{
	word = "Abspann";
	wordSize = word.length();
}

int CreditsButton::run()
{
	Credits credits;
	credits.run();

	return 0;
}
