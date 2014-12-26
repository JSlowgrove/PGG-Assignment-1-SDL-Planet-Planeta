/*Made using information from the following link : http://blog.nuclex-games.com/tutorials/cxx/game-state-management/*/

#pragma once
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include "state.h"

/**
@brief 
*/
class StateManager
{
private:
	/*the current states that are on the stack*/
	std::vector<State*> currentStates;
public:
	/**
	Constructs a StateManager object
	Constructs a StateManager object
	*/
	StateManager();

	/**
	De-constructs a StateManager object
	De-constructs the StateManager object
	*/
	~StateManager();

	void switchState(State*);

	void pushState(State*);

	State popState();

	State peek();

	void draw();

	void update();
};
#endif