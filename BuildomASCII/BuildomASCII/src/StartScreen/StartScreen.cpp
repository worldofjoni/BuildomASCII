#include "../pch/pch.h"
#include "StartScreen.h"


void StartScreen::run() 
{
	setBlank();

	/*char playButton[wordArraySize] = "play";
	char exitButton[wordArraySize] = "exit";*/

	char selection = '>';

	placeWord(1, 1, playButton->word, playButton->wordSize);

	//placeWord(1, 4, exitButton);

	printScreen();
	playButton->run();

}

void StartScreen::placeWord(int px, int py, char word[Button::wordArraySize], int wordSize) {
	
	
	int x = px;
	for (int i = 0; i < wordSize; i++)
	{
		
		content[py][x] = word[i];
		x++;
		
		
	}
}