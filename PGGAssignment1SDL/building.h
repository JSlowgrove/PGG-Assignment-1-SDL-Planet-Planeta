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
	*/
	Building(Texture * , int, int, int, int);

	/**
	De-constructs a Building object
	De-constructs the Building object
	*/
	~Building();
};
#endif