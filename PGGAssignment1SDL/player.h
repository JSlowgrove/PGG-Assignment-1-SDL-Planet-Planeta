#pragma once
#ifndef PLAYER_H
#define PLAYER_H

/**
@brief Creates a Player object.
*/
class Player
{
private:
	/*the Player details*/
	int resources;
	int power;
	int minionNumber;
	int maxMinions;
public:
	/**
	Constructs Player object
	Constructs a Player object
	*/
	Player();

	/**
	De-constructs a Player object
	De-constructs the Player object
	*/
	~Player();

	/**
	Setter # resources
	Sets the number of resources of the Player object to the inputed number of resources.
	@param int the inputed resources
	*/
	void setResources(int);

	/**
	Setter # power
	Sets the amount of power of the Player to the inputed amount of power.
	@param int the inputed power
	*/
	void setPower(int);

	/**
	Setter # minions
	Sets the number of minions of the Player object to the inputed number of minions.
	@param int the inputed minions
	*/
	void setMinions(int);

	/**
	Setter # max number of minions
	Sets the max number of minions of the Player object to the inputed max number of minions.
	@param int the inputed max number of minions
	*/
	void setMaxMinions(int);

	/**
	Getter # resources
	Returns the number of resources the Player has.
	*/
	int getResources();

	/**
	Getter # power
	Returns the amount of power of the Player.
	*/
	int getPower();

	/**
	Getter # minions
	Returns the number of minions the Player has.
	*/
	int getMinions();

	/**
	Getter # max number of minions
	Returns the max number of minions the Player can have.
	*/
	int getMaxMinions();
};
#endif