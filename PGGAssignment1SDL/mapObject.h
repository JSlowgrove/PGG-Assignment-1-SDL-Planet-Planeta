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
public:
	/**
	Constructs MapObject object
	Constructs a MapObject object.
	*/
	MapObject();

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
	@returns bool  does the object need deleting.
	*/
	bool getDeletable();
};
#endif