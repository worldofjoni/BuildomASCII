#ifndef LEVEL_H
#define LEVEL_H
#include "../LevelElement/LevelElement.h"

class Level
{
private:
public:
	const int WIDTH, HEIGHT;
	LevelElement ***map;
	Level(int with, int height);

	~Level(); // Rule of vive
	Level(const Level& other) = delete;
	Level(Level&& other) = delete;
	Level& operator=(const Level& other) = delete;
	Level& operator=(Level&& other) = delete;


};


#endif // !LEVEL_H
