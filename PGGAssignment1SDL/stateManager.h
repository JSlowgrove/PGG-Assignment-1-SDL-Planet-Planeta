#pragma once
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include "state.h"

/**
@brief Creates a State manager object.
Creates a State manager object to be inherited.
Made using information from http://blog.nuclex-games.com/tutorials/cxx/game-state-management/ and Peter Allen
*/
class StateManager
{
private:
	/*the current states that are in use*/
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

	/**
	Adds a new state
	Adds a new state to the current stack of states
	@param State * a pointer to the State in use
	*/
	void AddState(State*);

	/**
	Changes to a new State
	Changes the current State to a new State
	@param State * a pointer to the State in use
	*/
	void ChangeState(State*);

	/**
	Removes the last State from the vector
	Removes the last State from the vector
	*/
	void RemoveLastState();

	/**
	Handles the SDL events
	The SDL event handler function that will allow the equivalent SDL event handler function to run in the current State
	@returns bool if false then quit the application
	*/
	bool HandleSDLEvents();

	/**
	Updates the current State
	The update function that will allow the equivalent update function to run in the current State
	@param float the delta time for use within the update function
	*/
	void Update(float deltaTime);

	/**
	Draws the current State
	The draw function that will allow the equivalent draw function to run in the current State
	*/
	void Draw();
};
#endif