#pragma once
#ifndef BDALMANAGER_H
#define BDALMANAGER_H

#include <fstream>

enum LevelType {STORY = 0, CUSTOM = 1};


class BdalManager
{
private:
	const std::string basePath = "Level\\";
	const std::string fileEnding = ".bdal";
	std::string fileName;
	
	std::string advPath;
	std::string midDir;

	std::ofstream writeStream;
	std::ifstream readStream;

	int countOfElements;

	std::string elementInLine;
	char currentElementChar;



public:
	BdalManager();
	void getLevel(int levelID, LevelType levelType);
	void saveLevel(Level level);
	
};

#endif // !BDALMANAGER_H
