#include "pch/pch.h"
#include "Util.h"

Pos Pos::below()
{
	return { x, y + 1 };
}

char uts::getCharLow() {
	char input = 0;
	input = _getch();
	if (input >= 0) {
		if (isupper(input) && isalpha(input)) {
			input = _tolower(input);
		}
	}
	return input;
}