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
	/*pointers to entities used in the tests*/
	Player * player;
	MapLoader * map;
	Background * background;
public:
	/**
	Constructs an Collision object
	Constructs the Collision object.
	@param Player * pointer to the Player
	@param MapLoader * pointer to the MapLoader
	@param Background * pointer to the Background
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
	@param char the axis to test
	*/
	void playerCollisionTest(float, char);

	/**
	Gem collision action
	Performs the action that happens when the player collides with a Gem
	@param int the index of the Gem that has been collided with
	*/
	void gemAction(int);

	/**
	Block collision action on the x xis
	Performs the action that happens when the player collides with a Block on the x axis
	@param int the index of the Block that has been collided with
	*/
	void blockActionX(int);

	/**
	Block collision action on the y axis
	Performs the action that happens when the player collides with a Block on the y axis
	@param int the index of the Block that has been collided with
	*/
	void blockActionY(int);

	/**
	End goal collision action
	Performs the action that happens when the player collides with the end goal Block
	@param int the index of the Block that has been collided with
	*/
	void endGoalAction(int);

	/**
	Checks which way the position is rounded
	Checks which way the position is rounded and corrects the numbers accordingly
	@param float the updated position
	@param int a reference to the minimum pap position
	@param int a reference to the maximum pap position
	@param float the extra that needs to be added to the map coordinates, this depends on where the background is
	*/
	void roundingCheck(float, int &minMap, int &maxMap, float);

	/**
	The test and action to apply if the player is going left
	This could proberally be converted into a single function along with rightTest() and downTest(), time permitting.
	@param float the updated position
	@param int the max position along the current axis
	@param int the min position along the opposite axis
	@param int the max position along the opposite axis
	*/
	void leftTest(float, int, int, int);

	/**
	The test and action to apply if the player is going right
	This could proberally be converted into a single function along with leftTest() and downTest(), time permitting.
	@param float the updated position
	@param int the max position along the current axis
	@param int the min position along the opposite axis
	@param int the max position along the opposite axis
	*/
	void rightTest(float, int, int, int);

	/**
	The test and action to apply if the player is going down
	This could proberally be converted into a single function along with rightTest() and leftTest(), time permitting.
	@param float the updated position
	@param int the max position along the current axis
	@param int the min position along the opposite axis
	@param int the max position along the opposite axis
	*/
	void downTest(float, int, int, int);
};

#endif