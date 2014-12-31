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
	/*Block velocity*/
	float velocity;
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
	Setter # velocity
	Sets the velocity of the Block to the inputed velocity.
	@param float the inputed velocity
	*/
	void setVelocity(float);

	/**
	Updates the x position of the Block
	Updates the x position using the velocity and the inputed deltaTime.
	@param float the inputed deltaTime
	*/
	void updateX(float);

	/**
	Sets the type of the Block
	Uses the value of type to set up initial values for the Block
	@param int the type of background.
	*/
	void typeSetup(int);
};
#endif