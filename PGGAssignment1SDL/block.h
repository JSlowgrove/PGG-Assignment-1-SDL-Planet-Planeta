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
	/*the type of the Block*/
	int type;
public:
	/**
	Constructs a Block object
	Constructs the Block object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	@param int the Block type.
	@param int the type of background.
	*/
	Block(Texture *, float, float, int, int);

	/**
	De-constructs a Block object
	De-constructs the Block object
	*/
	~Block();

	/**
	Sets the type of the Block
	Uses the value of type to set up initial values for the Block
	@param int the type of background.
	*/
	void typeSetup(int);

	/**
	Getter # type
	@returns int the type.
	*/
	int getType();
};
#endif