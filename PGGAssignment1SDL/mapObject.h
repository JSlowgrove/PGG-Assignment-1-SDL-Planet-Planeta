#pragma once
#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "entity.h"

/**
@brief Creates a MapObject object that inherits Entity.
*/
class MapObject : public Entity
{
protected:
	/*is the object collidable?*/
	bool collidable;
	/*if a collision does the object remove a life?*/
	bool damaging;
	/*does the object need to be deleted?*/
	bool deleteable;
	/*Gem velocity*/
	float velocity;
	/*position check variables*/
	int minX;
	int maxX;
	/*can the Background move?*/
	bool moveable;
public:
	/**
	Constructs a MapObject object
	Constructs the MapObject object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	*/
	MapObject(Texture *, float, float);

	/**
	De-constructs a MapObject object
	De-constructs the MapObject object
	*/
	~MapObject();

	/**
	Setter # collidable
	Sets if the object is able to be collided with.
	@param bool the collision boolean
	*/
	void setCollidable(bool);

	/**
	Getter # collidable
	Gets if the object is collidable
	@returns bool if the mapObject is collidable.
	*/
	bool getCollidable();

	/**
	Setter # damaging
	Sets if the object causes damaging to the player.
	@param bool the object causes damaging to the player.
	*/
	void setDamaging(bool);

	/**
	Getter # damaging
	@returns bool if the object causes damaging to the player.
	*/
	bool getDamaging();

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
	Setter # velocity
	Sets the velocity of the MapObject to the inputed velocity.
	@param float the inputed velocity
	*/
	void setVelocity(float);

	/**
	Updates the x position of the MapObject
	Performers a check on the updated position of the x to see if it within boundaries.
	If it is within boundaries then it updates the x position using the velocity and the inputed
	deltaTime.
	If it is not within boundaries then it resets the x position to the boundaries.
	@param float the inputed deltaTime
	*/
	void updateX(float);


	/**
	Getter # velocity
	@returns the velocity of the MapObject.
	*/
	float getVelocity();
};
#endif