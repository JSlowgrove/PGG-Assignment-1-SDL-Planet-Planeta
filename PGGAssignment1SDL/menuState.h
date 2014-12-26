/*Made using information from the following link : http://blog.nuclex-games.com/tutorials/cxx/game-state-management/*/

#pragma once
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"

/**
@brief
*/
class MenuState : State
{
private:
public:
	/**
	Constructs a MenuState object
	Constructs a MenuState object
	*/
	MenuState();

	/**
	De-constructs a MenuState object
	De-constructs the MenuState object
	*/
	~MenuState();

	/**
	Called after the MenuState has been placed in the StateManager.
	*/
	void entered();

	/**
	Called right before the MenuState is removed from the StateManager.
	*/
	void leaving();

	/**
	Called right before another MenuState is stacked on top of this one.
	*/
	void obscuring();

	/**
	Called after the MenuState has become the topmost State on the stack again.
	*/
	void revealed();
};
#endif