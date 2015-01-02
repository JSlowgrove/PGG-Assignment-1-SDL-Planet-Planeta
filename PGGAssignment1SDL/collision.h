#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "mapLoader.h"
#include "background.h"

/**
@brief Creates an Collision object.
The Collision object is for use with detecting Collision.
Used help from http://higherorderfun.com/blog/2012/05/20/the-guide-to-implementing-2d-platformers/ in the type 2 section.
*/
class Collision
{
private:
	Player * player;
	MapLoader * map;
	Background * background;
public:
	/**
	Constructs an Collision object
	Constructs the Collision object.
	@param Player * pointer to the Player
	@param MapLoader * pointer to the MapLoader
	*/
	Collision(Player *, MapLoader *, Background *);

	/**
	De-constructs an Collision object
	De-constructs the Collision object
	*/
	~Collision();

	/**
	Player collision test
	Tests if the Player collides with an object.
	@param float the delta time
	*/
	void playerCollisionTest(float);

	/**
	Gem collision action
	Performs the action that happens when the player collides with a Gem
	@param int the index of the Gem that has been collided with
	*/
	void gemAction(int);

	/**
	Block collision action
	Performs the action that happens when the player collides with a Block
	@param int the index of the Block that has been collided with
	*/
	void blockAction(int);

	void roundingCheck(float, int &minMap, int &maxMap, float);

	void leftTest(float, int, int, int);

	void rightTest(float, int, int, int);

	void upTest();

	void downTest();
};

#endif