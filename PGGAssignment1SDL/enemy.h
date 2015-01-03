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
	/*the type of the Enemy*/
	int type;
public:
	/**
	Constructs an Enemy object
	Constructs the Enemy object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	@param int the Enemy type.
	*/
	Enemy(Texture *, float, float, int);

	/**
	De-constructs an Enemy object
	De-constructs the Enemy object
	*/
	~Enemy();

	/**
	Sets the type of the Enemy
	Uses the value of type to set up initial values for the Enemy
	*/
	void typeSetup();
};
#endif