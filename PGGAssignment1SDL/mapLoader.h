#pragma once

#include <SDL.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "texture.h"
#include "mapObject.h"
#include "block.h"
#include "gem.h"
#include "enemy.h"

/**
@brief a class to load in a map text file*/
class MapLoader
{
private:
	/*a structure for use with the map array*/
	struct id
	{
		/*the type of entity*/
		char type;
		/*the index of the types array*/
		int index;
	};
	/*vectors for the loaded map*/
	std::vector<std::vector<id>> entities;
	std::vector<Block *> blocks;
	std::vector<Gem *> gems;
	std::vector<Enemy *> enemies;
	/*number of entities in a row*/
	int numberOfEntites;
	/*number of rows in the map*/
	int numberOfRows;
	/*number of blocks in the map*/
	int numberOfBlocks;
	/*number of gems in the map*/
	int numberOfGems;
	/*number of enemies*/
	int numberOfEnemies;
	/*pointer to the spritesheet*/
	Texture * texture;
public:
	/**
	Constructs MapLoader object
	Constructs a MapLoader object.
	@param std::string the file location
	@param Texture * a pointer to the spritesheet
	@param int the type of background*/
	MapLoader(std::string, Texture *, int);

	/**
	De-constructs a MapLoader object
	De-constructs the MapLoader object*/
	~MapLoader();

	/**load the map file
	load the map file from the location passed in.
	@param std::string the file location
	@param int the type of background*/
	void loadMap(std::string, int);

	/**sort the map file object types
	take in the value of the current loaded type and declare the current map object to its correct type.
	@param int the type of the object
	@param int the i index for the x position
	@param int the j index for the y position
	@param int the type of background*/
	void sortType(int, int, int, int);

	/**display the Block object
	display the Block at the position at the array inputed
	@param int the index of the Block array
	@param SDL_Renderer * a pointer to the renderer*/
	void displayBlock(int, SDL_Renderer *);

	/**display the Gem object
	display the Gem at the position at the array inputed
	@param int the index of the Gem array
	@param SDL_Renderer * a pointer to the renderer*/
	void displayGem(int, SDL_Renderer *);

	/**display the Enemy object
	display the Enemy at the position at the array inputed
	@param int the index of the Enemy array
	@param SDL_Renderer * a pointer to the renderer*/
	void displayEnemy(int, SDL_Renderer *);

	/**
	Getter # number of blocks
	@returns the number of blocks.
	*/
	int getNumberOfBlocks();

	/**
	Getter # height
	@returns the number of gems.
	*/
	int getNumberOfGems();

	/**
	Getter # height
	@returns the number of enemies.
	*/
	int getNumberOfEnemies();

	/**
	Getter # a Block from the array
	@param int the index of the block
	@returns a pointer to a Block.
	*/
	Block * getBlock(int);

	/**
	Getter # a Block from the array
	@param int the index of the Block
	@returns a pointer to a Block.
	*/
	Gem * getGem(int);

	/**
	Getter # a Enemy from the array
	@param int the index of the Enemy
	@returns a pointer to a Enemy.
	*/
	Enemy * getEnemy(int);

	/**
	Getter # number of Entities in a row
	@returns the number of Entities in a row.
	*/
	int getNumberOfEntities();

	/**
	Getter # number of rows
	@returns the number of rows.
	*/
	int getNumberOfRows();

	/**
	Getter # the type of the array
	@param int i index
	@param int j index
	@returns the type of the position in the array.
	*/
	char getType(int, int);

	/**
	Getter # the index of the type array
	@param int i index
	@param int j index
	@returns the type of the index in the types array.
	*/
	int getIndex(int, int);

	/**
	Setter # the contents at the position to blank
	Sets the content at the [i][j] position in the array to be a empty tile
	@param int i index
	@param int j index
	*/
	void MapLoader::setEntityBlank(int, int);
};
