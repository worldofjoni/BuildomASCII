#include "pch/pch.h"
#include "BdalManager.h"

BdalManager::BdalManager()
{
}

void BdalManager::getLevel(int levelID, LevelType levelType)
{
	Level level;


	switch (levelType)
	{
	case LevelType::STORY:
		midDir = "Story Level\\";
		fileName = "sLevel_";
		break;
	case LevelType::CUSTOM:
		midDir = "Custom Level\\";
		fileName = "cLevel_";
		break;
	default:
		break;
	}



	advPath = basePath + midDir + fileName + std::to_string(levelID) + fileEnding;

	readStream.open(advPath);

	if (!readStream.is_open())
	{
		std::cout << "ERROR";
		return;
	}

	// Read-part

	// Start Point
	readStream >> level.start.x;
	readStream >> level.start.y;
	
	
	// End Point
	readStream >> level.end.x;
	readStream >> level.end.y;

	// maxElements
	readStream >> countOfElements;

	for (int i = 0; i < countOfElements; i++)
	{
		
		readStream >> level.maxElements[i];
		
		
	}


	// Level itself

	for (int y = 0; y < level.HEIGHT; y++)
	{
		readStream >> elementInLine;
		for (int x = 0; x < level.WIDTH; x++)
		{
			currentElementChar = elementInLine[x];

			switch (currentElementChar)
			{
			case 219:
				level.placeAt(new Solid(false), x, y);
				break;
			case '\\':
				level.placeAt(new SlopeDown(false), x, y);
				break;
			case '/':
				level.placeAt(new SlopeUp(false), x, y);
				break;
			case 30:
				level.placeAt(new Spike(false), x, y);
				break;
			case 29:
				level.placeAt(new ChangeDir(false), x, y);
				break;
			default:
				break;
			}
		}
	}

	readStream.close();

}

void BdalManager::saveLevel(Level level)
{
}
