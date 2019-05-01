#ifndef BUILD_H
#define BUILD_H
#include "../Screen/Screen.h"
#include "../Level/Level.h"


enum Direction
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
	
class Curser
{
private:
	Level* level;
public:
	Curser(Level* level);
	int x = 0, y = 0;
	void move(Direction dir);
	bool isVisable = true; // if curser is visible
	char symbol = 'x';
};



class Build : public Screen
{
private:
	Level level;



public:
	Build(Level level);
	void run();



};



#endif