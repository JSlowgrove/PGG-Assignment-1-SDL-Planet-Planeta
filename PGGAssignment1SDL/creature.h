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
	/*velocitys of the Creature*/
	float velocityX;
	float velocityY;
public:
	/**
	Constructs Creature object
	Constructs a Creature object.
	*/
	Creature();

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
	Returns the x velocity of the Creature object.
	*/
	float getVelocityX();

	/**
	Getter # y velocity
	Returns the y velocity of the Creature object.
	*/
	float getVelocityY();
};
#endif