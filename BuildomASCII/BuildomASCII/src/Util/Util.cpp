// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Level/Level.h"

Pos Pos::below()
{
	return { x, y + 1 };
}

bool Pos::isOnLevelBorder()
{
	if (x == 0 || y == 0 || x == Level::WIDTH - 1 || y == Level::HEIGHT - 1) return true;
	return false;
}

bool Pos::operator==(Pos other)
{
	return (x == other.x && y == other.y);
}

bool Pos::operator!=(Pos other)
{
	return !((*this) == other);
}

char getCharLow() // Returns pressed keyboard value in lower-case
{
	char input = 0;
	input = _getch();
	if (input >= 0)
	{
		if (isupper(input) && isalpha(input))
		{
			input = _tolower(input);
		}
	}
	return input;
}

void openSound()
{
	fc::beep(NOTE_C, 50);
	fc::beep(NOTE_F, 50);
	fc::beep(NOTE_H, 50);
}

void closeSound()
{
	fc::beep(NOTE_H, 50);
	fc::beep(NOTE_F, 50);
	fc::beep(NOTE_C, 50);
}

void winSound()
{
	fc::beep(NOTE_E, 50);
	fc::beep(NOTE_H, 500);
}

void deathSound()
{
	fc::beep(NOTE_G, 50);
	fc::beep(NOTE_C, 500);
}


static bool musicAllowedVar = true;

void playMusic(const char str[])
{
	if (musicAllowedVar) fc::playSoundRepeat(str);
}

bool& musicAllowed()
{
	return musicAllowedVar;
}

void printMultiline(Pos pos, std::string str, int width, fc::Color textColor, fc::Color backColor)	// Prints Outlines of strings
{
	fc::setTextColor(textColor);
	fc::setBackgroundColor(backColor);
	str = str.substr(1, str.length()); // to delete the first \n
	int i = 0, x = pos.x, y = pos.y;
	while (i < str.length())
	{
		while (str[i] != '\n' && (x + i) < Screen::WIDTH)
		{
			fc::setCursorPos(x + i, y);
			switch (str[i])
			{
			case 'ä':
				std::cout << (char)132;
				break;
			case 'ö':
				std::cout << (char)148;
				break;
			case 'ü':
				std::cout << (char)129;
				break;
			case 'Ä':
				std::cout << (char)142;
				break;
			case 'Ö':
				std::cout << (char)153;
				break;
			case 'Ü':
				std::cout << (char)154;
				break;
			case 'ß':
				std::cout << (char)225;
				break;
			default:
				std::cout << str[i];
				break;
			}
			i++;
		}
		str = str.substr((str[i] == '\n') ? i + 1 : i, str.length());
		i = 0;
		y++;
	}

}

bool isInt(std::string str)
{
	if (str.length() >= 9) 
		return false;

	for (int i = 0; i < str.length(); i++) if (str[i] < 0) 
		return false;

	if (!(str[0] == '-' || isdigit(str[0]))) 
		return false;

	for (int i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i])) 
			return false;
	}
	return true;
}

bool isFilename(std::string str)
{
	if (str.length() > 20) 
		return false;

	for (int i = 0; i < str.length(); i++) if (str[i] < 0) 
		return false;

	for (int i = 0; i < str.length(); i++)
	{
		if (isalnum(str[i]) == 0 && str[i] != '_')
			return false;
	}
	return true;
}
