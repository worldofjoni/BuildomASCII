#include "pch/pch.h"
#include "BdalManager.h"

void BdalManager::addCustomName(std::string name)
{

	std::string customNames[100];
	nameCount = getCustomLvlNames(customNames);
	customNames[nameCount] = name;
	nameCount++;

	writeStream.open(cNamePath);
	writeStream << nameCount << std::endl;

	for (int i = 0; i < nameCount; i++)
	{
		writeStream << customNames[i] << std::endl;
	}
	writeStream.close();

}

int BdalManager::getCustomLvlNames(std::string nameList[100])
{
	nameCount = 0;

	for (const auto& entry : std::experimental::filesystem::directory_iterator(cNamePath))
	{
		nameList[nameCount] = entry.path().string();
		nameList[nameCount] = nameList[nameCount].substr(nameList[nameCount].find_last_of('\\') +1, nameList[nameCount].length());
		nameList[nameCount] = nameList[nameCount].substr(0, nameList[nameCount].find('.'));
		nameCount++;
		

	}
	return nameCount;
}

int BdalManager::getStoryCount()
{
	nameCount = 0;

	for (const auto& entry : std::experimental::filesystem::directory_iterator(sNamePath))
	{
		nameCount++;


	}
	return nameCount;
}

BdalManager::BdalManager()
{
}

Level BdalManager::getLevel(std::string levelName, LevelType levelType)
{
	Level level;
	Pos start;
	Pos end;
	int maxElements[LevelElement::countOfElements];

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		maxElements[i] = 0;
	}
	
	switch (levelType)
	{
	case LevelType::STORY:
		midDir = "Story Level\\";
		fileName = "sLevel_";
		break;
	case LevelType::CUSTOM:
		midDir = "Custom Level\\";
		fileName = "";
		break;
	default:
		break;
	}



	advPath = basePath + midDir + fileName + levelName + fileEnding;

	readStream.open(advPath);

	if (!readStream.is_open())
	{
		std::cout << "ERROR";
		return level;
	}

	// Read-part

	// Start Point
	readStream >> start.x;
	readStream >> start.y;
	
	
	// End Point
	readStream >> end.x;
	readStream >> end.y;

	level.setStartEnd(start, end);

	// maxElements
	readStream >> countOfElements;

	for (int i = 0; i < countOfElements; i++)
	{
		
		readStream >> maxElements[i];
		
		
	}
	level.setMaxElements(maxElements);


	// Level itself
	for (int y = 0; y < level.HEIGHT; y++)
	{
		for (int x = 0; x < level.WIDTH; x++)
		{
			readStream >> currentElementChar;

			switch (currentElementChar) // manualy update ###################################################################################
			{
			case Solid::ownId:
				level.placeAt(new Solid(false), x, y);
				break;
			case SlopeUp::ownId:
				level.placeAt(new SlopeUp(false), x, y);
				break;
			case SlopeDown::ownId:
				level.placeAt(new SlopeDown(false), x, y);
				break;
			case ChangeDir::ownId:
				level.placeAt(new ChangeDir(false), x, y);
				break;
			case Spike::ownId:
				level.placeAt(new Spike(false), x, y);
				break;
			case Star::ownId:
				level.placeAt(new Star(false), x, y);
				break;
			case NonDelEmpty::ownId:
				level.placeAt(new NonDelEmpty(false), x, y);
				break;
			default:
				break;
			}
		}
	}
	readStream.close();
	return level;


}

bool BdalManager::saveLevel(Level level, std::string cusLvlName, bool overwrite)
{
	midDir = "Custom Level\\";
	advPath = basePath + midDir + cusLvlName + fileEnding;

	readStream.open(advPath);

	if (readStream.is_open() && !overwrite)
	{
		readStream.close();
		return false;
	}

	writeStream.open(advPath);


	// Write-Part

	// Start Point
	writeStream << level.start.x << std::endl;
	writeStream << level.start.y << std::endl;


	// End Point
	writeStream << level.end.x << std::endl;
	writeStream << level.end.y << std::endl;

	// maxElements
	writeStream << LevelElement::countOfElements << std::endl;

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{

		writeStream << level.maxElements[i] << std::endl;


	}

	// Level itself

	for (int y = 0; y < level.HEIGHT; y++)
	{
		for (int x = 0; x < level.WIDTH; x++)
		{

			writeStream << level.at({ x, y })->id << std::endl;
		}
		
	}


	writeStream.close();

	addCustomName(cusLvlName);
	return true;
}


char BdalManager::fileCheck()
{
	int count = 0;

	for (const auto& entry : std::experimental::filesystem::directory_iterator(sNamePath))
	{
		count++;
	}
	if (count == 0)
		return 's';
	

	count = 0;
	for (const auto& entry : std::experimental::filesystem::directory_iterator(musicPath))
	{
		count++;
	}
	if (count == 0)
		return 'm';
	return 'n';
}
bool BdalManager::deleteCusLevel(std::string delLvlName)
{
	std::string deleteLevelPath = cNamePath + delLvlName + fileEnding;
	readStream.open(deleteLevelPath);
	if (!readStream.is_open())
	{
		return false;
	}
	readStream.close();
	remove(deleteLevelPath.c_str());
	return true;
	
}
