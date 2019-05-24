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
	


	readStream.open(cNamePath);
	readStream >> nameCount;

	for (int i = 0; i < nameCount; i++)
	{
		readStream >> nameList[i];
	}

	readStream.close();
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
		std::cerr << "ERROR";
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
		//elementInLine.resize(level.WIDTH);
		for (int x = 0; x < level.WIDTH; x++)
		{
			readStream >> currentElementChar;

			switch (currentElementChar)
			{
			case 1:
				level.placeAt(new Solid(false), x, y);
				break;
			case 2:
				level.placeAt(new SlopeUp(false), x, y);
				break;
			case 3:
				level.placeAt(new SlopeDown(false), x, y);
				break;
			case 4:
				level.placeAt(new ChangeDir(false), x, y);
				break;
			case 5:
				level.placeAt(new Spike(false), x, y);
				break;
			default:
				break;
			}
		}
	}
	return level;

	readStream.close();

}

bool BdalManager::saveLevel(Level level, std::string cusLvlName)
{
	midDir = "Custom Level\\";
	advPath = basePath + midDir + cusLvlName + fileEnding;

	readStream.open(advPath);

	if (readStream.is_open())
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
