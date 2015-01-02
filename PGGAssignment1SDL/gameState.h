#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <time.h>
#include "state.h"
#include "stateManager.h"
#include "texture.h"
#include "background.h"
#include "player.h"
#include "gem.h"
#include "block.h"
#include "mapLoader.h"
#include "collision.h"

/**
@brief Creates a GameState object.
Creates a GameState object that inherits State
*/
class GameState : public State
{
private:
	/*spritesheets*/
	Texture * backgrounds;
	Texture * spritesheet;
	Texture * numbers;
	/*entities*/
	Background * background;
	Player * player;
	MapLoader * map;
	/*collision*/
	Collision * collision;
	/*input commands*/
	bool cmdJump, cmdLeft, cmdRight;
	/*is the player in the middle of the screen*/
	//bool centered;

public:
	/**
	Constructs a GameState object
	Constructs a GameState object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer in use.
	*/
	GameState(StateManager *, SDL_Renderer *);

	/**
	De-constructs a GameState object
	De-constructs the GameState object
	*/
	~GameState();

	/**
	A function to handle the SDL events
	A function to handle the SDL events for use with the GameState
	@returns bool if false then quit GameState
	*/
	bool HandleSDLEvents();

	/**
	A function to update the GameState
	A function to update the GameState to allow the GameState to run
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

	/**
	A function to update the entire scene
	Updates the scenes velocity using the inputed velocity
	@param float the new velocity
	*/
	void updateScene(float velocity);
};
#endif