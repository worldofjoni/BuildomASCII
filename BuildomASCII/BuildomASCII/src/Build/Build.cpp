#include "pch/pch.h"
#include "Build.h"

#include "LevelElement/LevelElement.h"
#include "Curser/Curser.h"


Build::Build(Level level)
	:level(level)
{
	// initializes the content to he symbols of the level at each spot
	for (int x = 0; x < this->level.WIDTH; x++)
	{
		for (int y = 0; y < this->level.HEIGHT; y++)
		{
			content[x][y] = this->level.map[x][y]->symbol;
		}
	}

}




void Build::run()
{
	

	int key = ' ';
	LevelElement *setElement = nullptr; // Elemet player can set on screen
	Direction dir = NONE;
	Curser curser(&level);
	printScreen();

	while (true)
	{
		if (_kbhit())
		{
			key = _getch();
			switch (key)
			{
			case 'w':
				dir = UP;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case '1':
				setElement = new Solid;
				break;
			case '2':
				setElement = new Empty;
				break;
			default:
				dir = NONE;
				break;
			}

			// if a new Element schould be set...
			if (setElement != nullptr)
			{
				delete level.map[curser.x][curser.y];
				level.map[curser.x][curser.y] = setElement;
				setElement = nullptr;
			}

			// deleting old
			fc::setCurserPos(curser.x, curser.y);
			fc::setTextColor(level.map[curser.x][curser.y]->color);
			std::cout << level.map[curser.x][curser.y]->symbol;

			curser.move(dir);

			
			// printing new
			
			
			fc::setCurserPos(curser.x, curser.y);
			fc::setTextColor(curser.color);
			std::cout << curser.symbol;
				
			
			
			

		}
		else
		{
			// only blinking when not moving
			fc::setCurserPos(curser.x, curser.y);
			fc::setTextColor(curser.isVisable ? curser.color : level.map[curser.x][curser.y]->color);
			std::cout << (curser.isVisable ? curser.symbol : level.map[curser.x][curser.y]->symbol); // Prints curser or not for blinking

		}

		dir = NONE;

		

		fc::setCurserPos(0, 0);// put Console curser away

		auto t2 = std::chrono::system_clock::now();
		while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - t2).count() < 500)
		{
			if (_kbhit()) // interupt on keypress
				break;
			
		}
		//waits 200ms

		curser.isVisable = !curser.isVisable;

	}


	




}

