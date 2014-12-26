/*Made using information from the following link : http://blog.nuclex-games.com/tutorials/cxx/game-state-management/*/

#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

/**
@brief
*/
class GameState : State
{
private:
public:
	/**
	Constructs a GameState object
	Constructs a GameState object
	*/
	GameState();

	/**
	De-constructs a GameState object
	De-constructs the GameState object
	*/
	~GameState();

	/**
	Called after the GameState has been placed in the StateManager.
	*/
	void entered();

	/**
	Called right before the GameState is removed from the StateManager.
	*/
	void leaving();

	/**
	Called right before another GameState is stacked on top of this one.
	*/
	void obscuring();

	/**
	Called after the GameState has become the topmost State on the stack again.
	*/
	void revealed();
};
#endif