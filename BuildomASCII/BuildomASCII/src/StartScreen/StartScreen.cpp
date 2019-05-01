#include "../pch/pch.h"
#include "../StartScreen/StartScreen.h"


void StartScreen::run() 
{
	setBlank();

	char playButton[wordArraySize] = "play";
	char exitButton[wordArraySize] = "exit";

	char selection = '>';

	placeWord(1, 1, playButton);

	placeWord(1, 4, exitButton);

	printScreen();

}

void StartScreen::placeWord(int px, int py, char word[wordArraySize]) {
	
	int i = 0;
	for (int x = px; x < wordArraySize; x++)
	{
		
		content[py][x] = word[i];
		i++;
		
		
	}
}