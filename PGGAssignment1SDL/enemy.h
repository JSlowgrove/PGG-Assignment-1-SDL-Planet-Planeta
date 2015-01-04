#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "creature.h"

/**
@brief Creates an Enemy object that inherits MapObject which in turn inherits Creature.
*/
class Enemy : public Creature
{
protected:
	/*the type of the Enemy*/
	int type;
	/*deleteable bool*/
	bool deleteable;
	/*the speed of the enemy*/
	float speed;
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

	/**
	Setter # deleteable
	Sets if the object needs to be deleted.
	@param bool does the object need deleting.
	*/
	void setDeletable(bool);

	/**
	Getter # deleteable
	@returns bool does the object need deleting.
	*/
	bool getDeletable();

	/**
	Setter # speed
	Sets the speed of the enemy.
	@param float the new speed.
	*/
	void setSpeed(float);

	/**
	Getter # speed
	@returns float the enemy's speed.
	*/
	float getSpeed();
};
#endif