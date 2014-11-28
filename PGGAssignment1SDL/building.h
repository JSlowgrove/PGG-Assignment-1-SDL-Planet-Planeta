#pragma once
#ifndef BUILDING_H
#define BUILDING_H

#include "entity.h"

/**
@brief Creates a Building object that inherits Entity.
*/
class Building : public Entity
{
private:
public:
	/**
	Constructs Building object
	Constructs a Building object.
	inputTexture, int spriteXNum, int spriteYNum
	@param Texture* a pointer to the spritesheet
	@int the number of the sprite in the spritesheet along the x axis
	@int the number of the sprite in the spritesheet along the y axis
	*/
	Building(Texture * , int, int);

	/**
	De-constructs a Building object
	De-constructs the Building object
	*/
	~Building();
};
#endif