#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entity.h"

/**
@brief Creates a Background object that inherits Entity.
Creates a Background object with a velocity, and position check.
It also has a Texture (including variables for the source and destination dimensions),
position and velocity in entity.
*/
class Background : public Entity
{
private:
	/*Background velocity*/
	float velocity;
	/*position check variables*/
	int minX;
	int maxX;
	/*can the Background move?*/
	bool moveable;
	/*Background type*/
	int backgroundType;
public:
	/**
	Constructs a Background object
	Constructs a Background object using the input Texture and background type.
	All of the other variables are automatically initialized to defaults.
	@param Texture* a pointer to a Texture loaded into memory.
	@param int an number between 0 an 2 that sets which of the 3 backgrounds is loaded from
	the texture.
	*/
	Background(Texture *, int);

	/**
	De-constructs a Background object
	De-constructs the Background object
	*/
	~Background();

	/**
	Setter # velocity
	Sets the velocity of the Background to the inputed velocity.
	@param float the inputed velocity
	*/
	void setVelocity(float);

	/**
	Updates the x position of the Background
	Performers a check on the updated position of the x to see if it within boundaries.
	If it is within boundaries then it updates the x position using the velocity and the inputed
	deltaTime.
	If it is not within boundaries then it resets the x position to the boundaries.
	@param float the inputed deltaTime
	*/
	void updateX(float);

	/**
	Getter # backgroundType
	@returns int the type of the Background.
	*/
	int getType();
};
#endif