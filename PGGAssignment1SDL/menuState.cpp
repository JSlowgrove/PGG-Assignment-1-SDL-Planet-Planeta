#include "menuState.h"
#include "gameState.h"

/**************************************************************************************************************/

/*Constructs the menu state object*/
MenuState::MenuState(StateManager * inStateManager, SDL_Renderer* renderer) : State(inStateManager, renderer)
{
	/*set state name*/
	name = "menu";
	/*set default mouse current position*/
	x = 100.0f;
	y = 100.0f;
	/*declare the texture for the background*/
	background = new Texture("img/menu.bmp", renderer, false);
}

/**************************************************************************************************************/

/*destructs the menu state object*/
MenuState::~MenuState()
{
	/*delete pointers*/
	delete background;
}

/**************************************************************************************************************/

/*handle the SDL events*/
bool MenuState::HandleSDLEvents()
{
	/*Check for user input*/
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{

		switch (incomingEvent.type)
		{
		case SDL_QUIT: /*If player closes the window end the game loop*/

			return false;
			break;

		case SDL_MOUSEBUTTONDOWN: /*If the mouse is pressed*/
			/*if the left mouse button set the x and y to the current mouse position*/
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{
				x = ((float)incomingEvent.motion.x) - 22;
				y = ((float)incomingEvent.motion.y) - 27;
			}
			/*go to the game state*/
			stateManager->ChangeState(new GameState(stateManager, renderer));
			break;

		case SDL_MOUSEBUTTONUP:/*If the mouse is released*/
			/*if the left mouse button*/
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{
			}
			break;
		}
	}
	return true;
}

/**************************************************************************************************************/

/*update the state*/
void MenuState::Update(float deltaTime)
{
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void MenuState::Draw()
{
	/*display the background*/
	background->pushToScreen(renderer,0,0);
}