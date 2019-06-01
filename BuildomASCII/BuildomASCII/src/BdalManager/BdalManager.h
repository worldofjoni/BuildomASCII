// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef BDALMANAGER_H
#define BDALMANAGER_H

#include <fstream>
#include <filesystem>


enum LevelType {STORY = 0, CUSTOM = 1};

class BdalManager
{
private:
	const std::string BASE_PATH = "Level\\";
	const std::string MUSIC_PATH = "music\\";
	const std::string FILE_ENDING = ".bdal";
	const std::string sNamePath = BASE_PATH + "Story Level\\";

	std::string fileName;
	
	std::string advPath;
	std::string midDir;

	std::ofstream writeStream;
	std::ifstream readStream;

public:
	BdalManager();

	const std::string cNamePath = BASE_PATH + "Custom Level\\";


	int getCustomLvlNames(std::string nameList[100]);
	int getStoryCount();
	Level getLevel(std::string levelName, LevelType levelType);
	bool saveLevel(Level level, std::string cusLvlName, bool overwrite = false);
	bool deleteCusLevel(std::string delLvlName);
	char fileCheck();
};

#endif // !BDALMANAGER_H
