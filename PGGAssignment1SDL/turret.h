#pragma once
#ifndef TURRET_H
#define TURRET_H

#include "entity.h"

/**
@brief Creates a Turret object that inherits Entity.
*/
class Turret : public Entity
{
private:
	/*details of the Turret*/
	int attack;
	float sightRadius;
public:
	/**
	Constructs Turret object
	Constructs a Turret object
	@param Texture* a pointer to the spritesheet
	@param int the inputed attack
	@param float the inputed radius
	@int the number of the sprite in the spritesheet along the x axis
	@int the number of the sprite in the spritesheet along the y axis
	*/
	Turret(Texture *, int, float, int, int);

	/**
	De-constructs a Turret object
	De-constructs the Turret object
	*/
	~Turret();

	/**
	Setter # attack
	Sets the attack of the Turret object to the inputed attack.
	@param int the inputed attack
	*/
	void setAttack(int);

	/**
	Getter # attack
	Returns the attack of the Turret object.
	*/
	int getAttack();

	/**
	Setter # sightRadius
	Sets the radius of the Turret object visible sight to the inputed radius.
	@param float the inputed radius
	*/
	void setSightRadius(float);

	/**
	Getter # sightRadius
	Returns the radius of the visible sight of the Turret object.
	*/
	float getSightRadius();
};
#endif