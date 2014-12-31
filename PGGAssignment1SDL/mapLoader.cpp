#include "mapLoader.h"

/**************************************************************************************************************/

/*Constructs the MapLoader object*/
MapLoader::MapLoader(std::string fileName, Texture * inTexture)
{
	/*declare the pointer to the texture*/
	texture = inTexture;
	/*initialise the size of the arrays*/
	numberOfGems = 0;
	numberOfBlocks = 0;
	/*load the map*/
	loadMap(fileName);
}

/**************************************************************************************************************/

/*De-constructs the MapLoader object*/
MapLoader::~MapLoader()
{
}

/**************************************************************************************************************/

/*loads the map into a 2d array*/
void MapLoader::loadMap(std::string fileName)
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

		/*for use with declaring the map objects*/
		int loadedMapType;
		
		/*Loop for the number of lines in the line array*/
		for (int i = 0; i < line.size(); i++)
		{
			/*set the first value of the row as it doesn't have a comma before it*/
			loadedMapType = (((int)line[i][0] - '0') * 10) + ((int)line[i][1] - '0');
			/*sorts the type*/
			sortType(loadedMapType, i, 0);

			/*loop for the number of characters in a single line*/
			for (int j = 0; j < line[i].size(); j++)
			{
				/*check if a comma then use the data after it to fill the array*/
				if (line[i][j] == ',')
				{
					/*loads in the number of the type of the next map object by converting two chars to a single int*/
					loadedMapType = (((int)line[i][j + 1] - '0') * 10) + ((int)line[i][j + 2] - '0');
					/*sorts the type*/
					sortType(loadedMapType, i, (j + 1) / 3);
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
void MapLoader::sortType(int type, int i, int j)
{
	/*KEY: Yellow Gem = 1, Green Gem = 2, Red Gem = 3, Blue Gem = 4, Top Wall = 5, 
	Top Right Wall = 6, Top Left Wall = 7, Middle Wall = 8, End Goal = 9*/
	switch (type)
	{
	case 1:/*Yellow Gem*/
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems-1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 16, 12, 0);
		break;
	case 2:/*Green Gem*/
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems - 1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 16, 12, 1);
		break;
	case 3:/*Red Gem*/
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems - 1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 16, 12, 2);
		break;
	case 4:/*Blue Gem*/
		numberOfGems++;
		gems.resize(numberOfGems);
		gems[numberOfGems - 1] = new Gem(texture, (float)(j * 32), (float)(i * 32), 16, 12, 3);
		break;
	case 5:/*Top Wall*/
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 3, 0, 0);
		break;
	case 6:/*Top Right Wall*/
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 4, 0, 0);
		break;
	case 7:/*Top Left Wall*/
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 2, 0, 0);
		break;
	case 8:/*Middle Wall*/
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 2, 1, 0);
		break;
	case 9:/*End Goal*/
		numberOfBlocks++;
		blocks.resize(numberOfBlocks);
		blocks[numberOfBlocks - 1] = new Block(texture, (float)(j * 32), (float)(i * 32), 10, 4, 0);
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