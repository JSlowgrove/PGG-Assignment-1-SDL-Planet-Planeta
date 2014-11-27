#pragma once
#ifndef MINION_H
#define MINION_H

#include "entity.h"

/**
@brief Creates a Minion object that inherits Entity.
*/
class Minion : public Entity
{
private:
	/*velocitys of the Minion*/
	float velocityX;
	float velocityY;
	/*details of the Minion*/
	int attack;
	float speed;
	float sightRadius;
public:
	/**
	Constructs Minion object
	Constructs a Minion object
	@param Texture* a pointer to the spritesheet
	@param int the inputed attack
	@param float the inputed speed
	@param float the inputed radius
	@int the number of the sprite in the spritesheet along the x axis
	@int the number of the sprite in the spritesheet along the y axis
	@int the inputed width of the sprite to be scaled to
	@int the inputed height of the sprite to be scaled to
	*/
	Minion(Texture *, int, float, float, int, int, int, int);

	/**
	De-constructs a Minion object
	De-constructs the Minion object
	*/
	~Minion();

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

	/**
	Setter # attack
	Sets the attack of the Minion object to the inputed attack.
	@param int the inputed attack
	*/
	void setAttack(int);

	/**
	Getter # attack
	Returns the attack of the Minion object.
	*/
	int getAttack();

	/**
	Setter # speed
	Sets the speed of the Minion object to the inputed speed.
	@param float the inputed speed
	*/
	void setSpeed(float);

	/**
	Getter # speed
	Returns the speed of the Minion object.
	*/
	float getSpeed();

	/**
	Setter # sightRadius
	Sets the radius of the Minion object visible sight to the inputed radius.
	@param float the inputed radius
	*/
	void setSightRadius(float);

	/**
	Getter # sightRadius
	Returns the radius of the visible sight of the Minion object.
	*/
	float getSightRadius();
};
#endif