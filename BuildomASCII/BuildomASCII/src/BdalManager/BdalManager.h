// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef BDALMANAGER_H
#define BDALMANAGER_H

#include <fstream>
#include <filesystem>
#include "Level/Level.h"

enum LevelType {STORY = 0, CUSTOM = 1};

class BdalManager
{
private:
	const std::string BASE_PATH = "Level\\";
	const std::string MUSIC_PATH = "music\\";
	const std::string FILE_ENDING = ".bdal";


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
	const std::string sNamePath = BASE_PATH + "Story Level\\";
	const std::string cNamePath = BASE_PATH + "Custom Level\\";

	int getCustomLvlNames(std::string nameList[100]);
	int getStoryCount();
	BdalManager();
	Level getLevel(std::string levelName, LevelType levelType);

	//return true if succeed
	bool saveLevel(Level level, std::string cusLvlName, bool overwrite = false);
	bool deleteCusLevel(std::string delLvlName);
	char fileCheck();
};

#endif // !BDALMANAGER_H
