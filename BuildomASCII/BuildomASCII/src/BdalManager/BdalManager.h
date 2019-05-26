#pragma once
#ifndef BDALMANAGER_H
#define BDALMANAGER_H

#include <fstream>
#include <filesystem>


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
	int currentElementChar;

	int nameCount;
	void addCustomName(std::string name);

public:
	const std::string cNamePath = basePath + "Custom Level\\";

	int getCustomLvlNames(std::string nameList[100]);
	BdalManager();
	Level getLevel(std::string levelName, LevelType levelType);

	//return true if succeed
	bool saveLevel(Level level, std::string cusLvlName, bool overwrite = false);
	bool deleteCusLevel(std::string delLvlName);
};

#endif // !BDALMANAGER_H
