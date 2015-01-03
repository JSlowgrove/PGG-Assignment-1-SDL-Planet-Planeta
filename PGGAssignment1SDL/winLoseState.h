#pragma once
#ifndef WINLOSESTATE_H
#define WINLOSESTATE_H

#include "state.h"
#include "stateManager.h"
#include "texture.h"

/**
@brief Creates a WinLoseState object.
Creates a WinLoseState object that inherits State
*/
class WinLoseState : public State
{
private:
	/*background*/
	Texture * background;
	Texture * winLoseKeys;
	Texture * afterWinLoseKey;
	Texture * numbers;
	/*details*/
	bool win;
	int score;
public:
	/**
	Constructs a WinLoseState object
	Constructs a WinLoseState object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer in use.
	@param bool if the player won or not
	@param int the players score
	*/
	WinLoseState(StateManager *, SDL_Renderer *, bool, int);

	/**
	De-constructs a WinLoseState object
	De-constructs the WinLoseState object
	*/
	~WinLoseState();

	/**
	A function to handle the SDL events
	A function to handle the SDL events for use with the WinLoseState
	@returns bool if false then quit WinLoseState
	*/
	bool HandleSDLEvents();

	/**
	A function to update the WinLoseState
	A function to update the WinLoseState to allow the WinLoseState to run
	@param float the delta time
	*/
	void Update(float deltaTime);

	/**
	A function to draw to the screen
	A function to draw to the screen using the renderer
	*/
	void Draw();

	/**
	A function to draw the score to the screen
	A function to draw the score to the screen using the renderer
	*/
	void displayScore();
};
#endif