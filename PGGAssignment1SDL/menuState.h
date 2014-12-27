#pragma once
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"
#include "stateManager.h"
#include "texture.h"

/**
@brief Creates a MenuState object.
Creates a MenuState object that inherits State
*/
class MenuState : public State
{
private:
	/*background*/
	Texture * background;
	Texture * menuKeys;
	/*mouseClickPosition*/
	float x;
	float y;
	/*int variables for if menu keys are highlighted, can be 0 or 1*/
	int playKey;
	int credKey;
	int exitKey;
	/*which key is pressed, 0 for none*/
	int pressed;
public:
	/**
	Constructs a MenuState object
	Constructs a MenuState object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer in use.
	*/
	MenuState(StateManager *, SDL_Renderer *);

	/**
	De-constructs a MenuState object
	De-constructs the MenuState object
	*/
	~MenuState();

	/**
	A function to handle the SDL events
	A function to handle the SDL events for use with the MenuState
	@returns bool if false then quit MenuState
	*/
	bool HandleSDLEvents();

	/**
	A function to update the MenuState
	A function to update the MenuState to allow the MenuState to run
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