/*Made using information from the following link : http://blog.nuclex-games.com/tutorials/cxx/game-state-management/*/

#pragma once
#ifndef STATE_H
#define STATE_H

/**
@brief
*/
class State
{
private:
public:
	/**
	Constructs a State object
	Constructs a State object
	*/
	State();

	/**
	De-constructs a State object
	De-constructs the State object
	*/
	~State();

	/**
	Called after the State has been placed in the StateManager.
	*/
	virtual void entered();

	/**
	Called right before the State is removed from the StateManager.
	*/
	virtual void leaving();

	/**
	Called right before another State is stacked on top of this one.
	*/
	virtual void obscuring();

	/**
	Called after the State has become the topmost State on the stack again.
	*/
	virtual void revealed();
};
#endif