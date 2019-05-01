#include "pch.h"
#include "Build.h"

#include "../LevelElement/LevelElement.h"


Curser::Curser(Level* level)
	:level(level)
{
}

// Moves Curser in direction
void Curser::move(Direction dir)
{
	switch (dir)
	{
	case NONE:
		break;
	case UP:
		if(y > 0)
			y--;
		break;
	case DOWN:
		if(y < level ->HEIGHT-1)
			y++;
		break;
	case LEFT:
		if (x > 0)
			x--;
		break;
	case RIGHT:
		if (x < level->WIDTH-1)
			x++;
		break;
	default:
		break;
	}
}


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
			std::cout << level.map[curser.x][curser.y]->symbol;

			curser.move(dir);

			
			// printing new
			if (curser.isVisable)
			{
				fc::setCurserPos(curser.x, curser.y);
				std::cout << curser.symbol;
				
			}
			
			

		}
		dir = NONE;

		fc::setCurserPos(curser.x, curser.y);
		std::cout << (curser.isVisable ? curser.symbol : level.map[curser.x][curser.y]->symbol); // Prints curser or not for blinking
		

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

