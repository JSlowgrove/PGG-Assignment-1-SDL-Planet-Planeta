#pragma once
#ifndef CREDITSSTATE_H
#define CREDITSSTATE_H

#include "state.h"
#include "stateManager.h"
#include "texture.h"

/**
@brief Creates a CreditsState object.
Creates a CreditsState object that inherits State
*/
class CreditsState : public State
{
private:
	/*the credit image*/
	Texture * credits;
public:
	/**
	Constructs a CreditsState object
	Constructs a CreditsState object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer in use.
	*/
	CreditsState(StateManager *, SDL_Renderer *);

	/**
	De-constructs a CreditsState object
	De-constructs the CreditsState object
	*/
	~CreditsState();

	/**
	A function to handle the SDL events
	A function to handle the SDL events for use with the CreditsState
	@returns bool if false then quit CreditsState
	*/
	bool HandleSDLEvents();

	/**
	A function to update the CreditsState
	A function to update the CreditsState to allow the CreditsState to run
	@param float the delta time
	*/
	void Update(float deltaTime);

	/**
	A function to draw to the screen
	A function to draw to the screen using the renderer
	*/
	void Draw();
};
#endif