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

/**
@brief a class to load in a map text file*/
class MapLoader
{
private:
	/*vectors for the loaded map*/
	std::vector<Block *> blocks;
	std::vector<Gem *> gems;
	/*number of blocks in the map*/
	int numberOfBlocks;
	/*number of gems in the map*/
	int numberOfGems;
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

	/**
	Getter # number of blocks
	@returns the number of blocks.
	*/
	int getNumberOfBlocks();

	/**
	Getter # height
	@returns the number of gems.
	*/
	int getNumberofGems();

	/**
	Getter # a Block from the array
	@param int the index of the block
	@returns a pointer to a Block.
	*/
	Block * getBlock(int);

	/**
	Getter # a Block from the array
	@param int the index of the block
	@returns a pointer to a Block.
	*/
	Gem * getGem(int);
};
