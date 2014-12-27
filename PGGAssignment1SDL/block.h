#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include "mapObject.h"

/**
@brief Creates a Block object that inherits MapObject.
*/
class Block : public MapObject
{
private:
	/*the type of the block*/
	int type;
public:
	/**
	Constructs a Block object
	Constructs the Block object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	@param int the sprite sheet x number.
	@param int the sprite sheet y number.
	@param int the Block type.
	*/
	Block(Texture *, float, float, int, int, int);

	/**
	De-constructs a Block object
	De-constructs the Block object
	*/
	~Block();
};
#endif