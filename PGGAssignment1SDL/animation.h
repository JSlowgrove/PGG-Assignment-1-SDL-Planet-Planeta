#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include "entity.h"

/**
@brief Creates a Animation object to handle the animations.
*/
class Animation
{
private:
	/*the timer float*/
	float timer;
	/*the length of the timer float*/
	float timerLength;
public:
	/**
	Constructs an Animation object
	Constructs the Animation object.
	@param float the length of the timer
	*/
	Animation(float);

	/**
	De-constructs a Animation object
	De-constructs the Animation object
	*/
	~Animation();

	/**
	Updates the timer
	Updates the timer using the delta time.
	If the timer is now greater than 1, then reset the timer to 0.
	@param float the delta time
	*/
	void upadateTimer(float);

	/**
	Updates the Animation
	If the timer is 0 update the Animation.
	@param char the type of the Animation
	@param Entity * the entity to use the Animation
	*/
	void upadateAnimation(char, Entity *);

	/**
	Performs the animation for the snail
	@param Entity * the entity to use the Animation
	*/
	void snailAnimation(Entity *);

	/**
	Performs the animation for the worm
	@param Entity * the entity to use the Animation
	*/
	void wormAnimation(Entity *);

	/**
	Performs the animation for the end goal
	@param Entity * the entity to use the Animation
	*/
	void endGoalAnimation(Entity *);

	/**
	Performs the timer test and animation for the Gem
	@param int the type of Gem
	@param Entity * the entity to use the Animation
	*/
	void gemAnimation(int, Entity *);
};
#endif