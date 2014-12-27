#pragma once
#ifndef STATE_H
#define STATE_H

#include <SDL.h>
#include <iostream>
#include <string.h>

/*forward declaration of StateManager for the pointer to the StateManager*/
class StateManager;

/**
@brief Creates a State object.
Creates a State object to be inherited.
Made using information from http://blog.nuclex-games.com/tutorials/cxx/game-state-management/ and Peter Allen
*/
class State
{
protected:
	/*A pointer to the state manager*/
	StateManager * stateManager;
	/*The render to display to*/
	SDL_Renderer * renderer;
	/*The name of the State*/
	std::string name;
public:
	/**
	Constructs a State object
	Constructs a State object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer in use.
	*/
	State(StateManager *, SDL_Renderer *);

	/**
	A virtual destructor for the State object
	A virtual destructor for the State object
	*/
	virtual ~State();

	/**
	A virtual function to handle the SDL events
	A virtual function to handle the SDL events for use with the State
	@returns bool if false then quit State
	*/
	virtual bool HandleSDLEvents() = 0;

	/**
	A virtual function to update the State
	A virtual function to update the State to allow the State to run
	@param float the delta time
	*/
	virtual void Update(float deltaTime) = 0;

	/**
	A virtual function to draw to the screen
	A virtual function to draw to the screen using the renderer
	*/
	virtual void Draw() = 0;

	/**
	Getter # State name
	@returns the name of the State.
	*/
	std::string GetStateName();
};
#endif