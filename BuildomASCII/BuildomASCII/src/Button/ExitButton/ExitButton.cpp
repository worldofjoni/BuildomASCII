#include "pch/pch.h"
#include "ExitButton.h"


ExitButton::ExitButton()
{
	wordSize = 4;
	word = "Exit";
}

void ExitButton::run()
{
	std::cout << "Exiting";
}
