#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "creature.h"

/**
@brief Creates an Enemy object that inherits Creature which in turn inherits Entity.
*/
class Enemy : public Creature
{
protected:
public:
	/**
	Constructs an Enemy object
	Constructs the Enemy object.
	*/
	Enemy();

	/**
	De-constructs an Enemy object
	De-constructs the Enemy object
	*/
	~Enemy();

};
#endif