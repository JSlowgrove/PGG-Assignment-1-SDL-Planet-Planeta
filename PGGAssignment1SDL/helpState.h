#pragma once
#ifndef HELPSTATE_H
#define HELPSTATE_H

#include "state.h"
#include "stateManager.h"
#include "texture.h"

/**
@brief Creates a HelpState object.
Creates a HelpState object that inherits State
*/
class HelpState : public State
{
private:
	/*the help image*/
	Texture * help;
public:
	/**
	Constructs a HelpState object
	Constructs a HelpState object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer in use.
	*/
	HelpState(StateManager *, SDL_Renderer *);

	/**
	De-constructs a HelpState object
	De-constructs the HelpState object
	*/
	~HelpState();

	/**
	A function to handle the SDL events
	A function to handle the SDL events for use with the HelpState
	@returns bool if false then quit HelpState
	*/
	bool HandleSDLEvents();

	/**
	A function to update the HelpState
	A function to update the HelpState to allow the HelpState to run
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