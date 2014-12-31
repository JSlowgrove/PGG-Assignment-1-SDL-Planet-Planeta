#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

/**
@brief Creates a Player object that inherits Creature which in turn inherits Entity.
*/
class Player : public Creature
{
private:
	/*the Player details*/
	int lives;
	int score;
public:
	/**
	Constructs a Player object
	Constructs the Player object.
	@param Texture* a pointer to a Texture loaded into memory.
	@param float initial x position.
	@param float initial y position.
	@param int the sprite sheet x number.
	@param int the sprite sheet y number.
	*/
	Player(Texture *, float, float, int, int);

	/**
	De-constructs a Player object
	De-constructs the Player object
	*/
	~Player();

	/**
	Setter # lives
	Sets the number of lives of the Player object to the inputed number.
	@param int the inputed number of lives
	*/
	void setLives(int);

	/**
	Getter # lives
	@returns int the number of lives the Player has.
	*/
	int getLives();

	/**
	Setter # score
	Sets the score of the Player object to the inputed number.
	@param int the inputed score
	*/
	void setScore(int);

	/**
	Getter # score
	@returns int the score the Player has.
	*/
	int getScore();
};
#endif