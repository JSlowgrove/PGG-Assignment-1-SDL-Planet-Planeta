#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include "texture.h"

/**
@brief Creates an Entity object
Creates an Entity object with a Texture (including variables for the source 
and destination dimensions) and position.
*/
class Entity
{
protected:
	/*the Texture variable*/
	Texture* texture;
	/*variables for the source and destination dimensions*/
	int srcWidth;
	int srcHeight;
	int srcX;
	int srcY;
	int width;
	int height;
	/*position*/
	float x;
	float y;
public:
	/**
	Constructs a Entity object
	Constructs the Entity object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	@param float initial sprite width.
	@param float initial sprite height.
	*/
	Entity(Texture *, float, float, int, int);

	/**
	De-constructs an Entity object
	De-constructs the Entity object
	*/
	~Entity();

	/**
	Displays the modified Texture renderer
	Pushes the texture to the renderer using the dimensions specified in the Entity.
	@param SDL_Renderer* The renderer.
	*/
	void display(SDL_Renderer *);

	/**
	Setter # x position
	Sets the x position of the Entity object to the inputed x position.
	@param float the inputed x position
	*/
	void setX(float);

	/**
	Setter # y position
	Sets the y position of the Entity object to the inputed y position.
	@param float the inputed y position
	*/
	void setY(float);

	/**
	Getter # x position
	@returns the x position of the Entity object.
	*/
	float getX();

	/**
	Getter # y position
	@returns the y position of the Entity object.
	*/
	float getY();

	/**
	Setter # source x position
	Sets the source x position of the Entity object to the inputed source x position.
	@param float the inputed source x position
	*/
	void setSrcX(float);

	/**
	Setter # source y position
	Sets the source y position of the Entity object to the inputed source y position.
	@param float the inputed source y position
	*/
	void setSrcY(float);

	/**
	Getter # source x position
	@returns int the source x position of the Entity object.
	*/
	int getSrcX();

	/**
	Getter # source y position
	@returns int the source y position of the Entity object.
	*/
	int getSrcY();
};
#endif