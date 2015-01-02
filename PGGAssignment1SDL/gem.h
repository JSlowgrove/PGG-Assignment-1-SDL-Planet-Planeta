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
	/*the type of the Gem*/
	int type;
	/*the value of the Gem*/
	int value;
public:
	/**
	Constructs a Gem object
	Constructs the Gem object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	@param int the Gem type.
	*/
	Gem(Texture *, float, float, int);

	/**
	De-constructs a Gem object
	De-constructs the Gem object
	*/
	~Gem();

	/**
	Sets the type of the Gem
	Uses the value of type to set up initial values for the Gem
	*/
	void typeSetup();

	/**
	Getter # value
	@returns int the value of the gem.
	*/
	int getValue();
};
#endif