#pragma once
#ifndef GEM_H
#define GEM_H

#include "mapObject.h"

/**
@brief Creates a Gem object that inherits MapObject.
*/
class Gem : public MapObject
{
private:
	/*the type of the gem, a number between 0 and 3*/
	int type;
public:
	/**
	Constructs a Gem object
	Constructs the Gem object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	@param int the sprite sheet x number.
	@param int the sprite sheet y number.
	@param int the Gem type.
	*/
	Gem(Texture *, float, float, int, int, int);

	/**
	De-constructs a Gem object
	De-constructs the Gem object
	*/
	~Gem();
};
#endif