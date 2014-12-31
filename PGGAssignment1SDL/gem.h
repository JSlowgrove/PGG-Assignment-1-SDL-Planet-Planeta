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
	/*Gem velocity*/
	float velocity;
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
	Setter # velocity
	Sets the velocity of the Gem to the inputed velocity.
	@param float the inputed velocity
	*/
	void setVelocity(float);

	/**
	Updates the x position of the Gem
	Updates the x position using the velocity and the inputed deltaTime.
	@param float the inputed deltaTime
	*/
	void updateX(float);

	/**
	Getter # value
	@returns int the value of the gem.
	*/
	int getValue();
};
#endif