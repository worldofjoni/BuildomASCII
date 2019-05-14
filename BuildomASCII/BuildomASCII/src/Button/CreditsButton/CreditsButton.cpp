#include "pch/pch.h"
#include "CreditsButton.h"
#include "Screen/Credits/Credits.h"

CreditsButton::CreditsButton()
{
	wordSize = 7;
	word = "Credits";
}

int CreditsButton::run()
{
	Credits credits;
	credits.run();

	return 0;
}
