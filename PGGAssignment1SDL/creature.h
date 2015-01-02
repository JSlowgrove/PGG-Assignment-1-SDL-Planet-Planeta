#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"

/**
@brief Creates a Creature object that inherits Entity.
*/
class Creature : public Entity
{
protected:
	/*velocities of the Creature*/
	float velocityX;
	float velocityY;
public:
	/**
	Constructs a Creature object
	Constructs the Creature object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	*/
	Creature(Texture *, float, float);

	/**
	De-constructs a Creature object
	De-constructs the Creature object
	*/
	~Creature();

	/**
	Setter # x velocity
	Sets the x velocity of the Creature object to the inputed velocity.
	@param float the inputed velocity
	*/
	void setVelocityX(float);

	/**
	Setter # y velocity
	Sets the y velocity of the Creature object to the inputed velocity.
	@param float the inputed velocity
	*/
	void setVelocityY(float);

	/**
	Updates the x position of the Creature
	@param float the inputed deltaTime
	*/
	void updateX(float);

	/**
	Updates the y position of the Creature
	@param float the inputed deltaTime
	*/
	void updateY(float);

	/**
	Getter # x velocity
	@returns the x velocity of the Creature object.
	*/
	float getVelocityX();

	/**
	Getter # y velocity
	@returns the y velocity of the Creature object.
	*/
	float getVelocityY();
};
#endif