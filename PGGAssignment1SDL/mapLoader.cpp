#include "mapLoader.h"

/**************************************************************************************************************/

/*Constructs the MapLoader object*/
MapLoader::MapLoader(std::string fileName, Texture * inTexture, int backgroundType)
{
	/*declare the pointer to the texture*/
	texture = inTexture;
	/*initialise the size of the arrays*/
	numberOfGems = 0;
	numberOfBlocks = 0;
	/*load the map*/
	loadMap(fileName, backgroundType);
}

/**************************************************************************************************************/

/*De-constructs the MapLoader object*/
MapLoader::~MapLoader()
{
}

/**************************************************************************************************************/

/*loads the map into a 2d array*/
void MapLoader::loadMap(std::string fileName, int backgroundType)
{
	/*open the file using a ifstream*/
	std::ifstream file(fileName);
	/*creates a vector of strings for the lines in the file*/
	std::vector<std::string> line;

	/*if the file successfully opens*/
	if (file.is_open())
	{
		/*file read in*/
		int i = -1, count = 0;
		std::string currentLine;
		/*while there are still lines to be read in from the file*/
		while (getline(file, currentLine))
		{
			i++;
			line.resize(i + 1);
			line[i] = currentLine;
		}
		file.close();

		/*update array sizes*/
		numberOfRows = line.size();
		entities.resize(numberOfRows);
		numberOfEntites = (line[0].size() + 1) / 3;
		for (int i = 0; i < numberOfRows; i++)
		{
			entities[i].resize(numberOfEntites);
		}
		
		int typeSetup;

		/*Loop for the number of lines in the line array*/
		for (int i = 0; i < line.size(); i++)
		{
			/*set the first value of the row as it doesn't have a comma before it*/
			typeSetup = (((int)line[i][0] - '0') * 10) + ((int)line[i][1] - '0');
			/*sorts the type*/
			sortType(typeSetup, i, 0, backgroundType);

			/*loop for the number of characters in a single line*/
			for (int j = 0; j < line[i].size(); j++)
			{
				/*check if a comma then use the data after it to fill the array*/
				if (line[i][j] == ',')
				{
					/*loads in the number of the type of the next map object by converting two chars to a single int*/
					typeSetup = (((int)line[i][j + 1] - '0') * 10) + ((int)line[i][j + 2] - '0');
					/*sorts the type*/
					sortType(typeSetup, i, (j + 1) / 3, backgroundType);
				}
				
			}
		}
	}
	/*if the file could be opened then output error message*/
	else
	{
		std::cout << "Unable to open file";
	}

}

/**************************************************************************************************************/

/*sort the type of the new map object*/
void MapLoader::sortType(int type, int i, int j, int backgroundType)
{
	/*KEY: Empty tile = 0, Yellow Gem = 1, Green Gem = 2, Red Gem = 3, Blue Gem = 4, Top Wall = 5, 
	Top Right Wall = 6, Top Left Wall = 7, Middle Wall = 8, End Goal = 9*/
	switch (type)
	{
	case 0:/*Empty tile*/
		entities[i][j].type = 'X';
		entities[i][j].index = 0;
		break;
	case 1:/*Yellow Gem*/
		entities[i][j].type = 'G';
		entities[i][j].index = numberOfGems;
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems-1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 0);
		break;
	case 2:/*Green Gem*/
		entities[i][j].type = 'G';
		entities[i][j].index = numberOfGems;
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems - 1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 1);
		break;
	case 3:/*Red Gem*/
		entities[i][j].type = 'G';
		entities[i][j].index = numberOfGems;
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems - 1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 2);
		break;
	case 4:/*Blue Gem*/
		entities[i][j].type = 'G';
		entities[i][j].index = numberOfGems;
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems - 1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 3);
		break;
	case 5:/*Top Wall*/
		entities[i][j].type = 'B';
		entities[i][j].index = numberOfBlocks;
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 0, backgroundType);
		break;
	case 6:/*Top Right Wall*/
		entities[i][j].type = 'B';
		entities[i][j].index = numberOfBlocks;
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 1, backgroundType);
		break;
	case 7:/*Top Left Wall*/
		entities[i][j].type = 'B';
		entities[i][j].index = numberOfBlocks;
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 2, backgroundType);
		break;
	case 8:/*Middle Wall*/
		entities[i][j].type = 'B';
		entities[i][j].index = numberOfBlocks;
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 3, backgroundType);
		break;
	case 9:/*End Goal*/
		entities[i][j].type = 'B';
		entities[i][j].index = numberOfBlocks;
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 4, backgroundType);
		break;
	}
}

/**************************************************************************************************************/

/*draw the block object to the screen*/
void MapLoader::displayBlock(int i, SDL_Renderer * renderer)
{
	/*display the object*/
	blocks[i]->display(renderer);
}

/**************************************************************************************************************/

/*draw the gem object to the screen*/
void MapLoader::displayGem(int i, SDL_Renderer * renderer)
{
	/*display the object*/
	gems[i]->display(renderer);
}

/**************************************************************************************************************/

/*get the number of blocks*/
int MapLoader::getNumberOfBlocks()
{
	/*return the number of blocks*/
	return numberOfBlocks;
}

/**************************************************************************************************************/

/*get the number of gems*/
int MapLoader::getNumberofGems()
{
	/*return the number of gems*/
	return numberOfGems;
}

/**************************************************************************************************************/

/*get the block*/
Block * MapLoader::getBlock(int i)
{
	/*return the block*/
	return blocks[i];
}

/**************************************************************************************************************/

/*get the gem*/
Gem * MapLoader::getGem(int i)
{
	/*return the gem*/
	return gems[i];
}

/**************************************************************************************************************/

/*get the number of entities*/
int MapLoader::getNumberOfEntities()
{
	/*return the number of entities*/
	return numberOfEntites;
}

/**************************************************************************************************************/

/*get the number of rows*/
int MapLoader::getNumberOfRows()
{
	/*return the number of rows*/
	return numberOfRows;
}

/**************************************************************************************************************/

/*get the type of the entity*/
char MapLoader::getType(int i, int j)
{
	/*return the number of entities*/
	return entities[i][j].type;
}

/**************************************************************************************************************/

/*get the index of the types array*/
int MapLoader::getIndex(int i, int j)
{
	/*return the index of the position in the types array*/
	return entities[i][j].index;
}

/**************************************************************************************************************/

/*sets the content at the [i][j] position in the array to be a empty tile*/
void MapLoader::setEntityBlank(int i, int j)
{
	/*set the value to the value of a blank tile*/
	entities[i][j].type = 'X';
	entities[i][j].index = 0;
}