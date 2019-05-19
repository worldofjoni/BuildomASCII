#pragma once
#ifndef BDALMANAGER_H
#define BDALMANAGER_H

#include <fstream>
#include "Position/Pos.h"


enum LevelType {STORY = 0, CUSTOM = 1};

class BdalManager
{
private:
	const std::string basePath = "Level\\";
	const std::string fileEnding = ".bdal";

	std::string cNamePath = basePath + "CustomLevelNames.txt";

	std::string fileName;
	
	std::string advPath;
	std::string midDir;

	std::ofstream writeStream;
	std::ifstream readStream;

	

	int countOfElements;
	int currentElementChar;

	int nameCount;
	void addCustomName(std::string name);

public:
	int getCustomLvlNames(std::string nameList[100]);
	BdalManager();
	Level getLevel(std::string levelName, LevelType levelType);

	//return true if succeed
	bool saveLevel(Level level, std::string cusLvlName);
	
};

#endif // !BDALMANAGER_H
