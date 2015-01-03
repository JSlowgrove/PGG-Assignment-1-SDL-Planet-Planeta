#include "creditsState.h"

/**************************************************************************************************************/

/*Constructs the credits state object*/
CreditsState::CreditsState(StateManager * inStateManager, SDL_Renderer* inRenderer) : State(inStateManager, inRenderer)
{
	/*declare the texture for the credits screen*/
	credits = new Texture("img/credits.bmp", renderer, true);
}

/**************************************************************************************************************/

/*destructs the credits state object*/
CreditsState::~CreditsState()
{
	/*delete pointers*/
	delete credits;
}

/**************************************************************************************************************/

/*handle the SDL events*/
bool CreditsState::HandleSDLEvents()
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
		case SDL_KEYDOWN: /*If a key is pressed*/

			switch (incomingEvent.key.keysym.sym)
			{
				/*If Escape is pressed*/
			case SDLK_ESCAPE:
				/*return to the menu*/
				stateManager->RemoveLastState();
				break;
			}
			break;
		}
	}
	return true;
}

/**************************************************************************************************************/

/*update the state*/
void CreditsState::Update(float deltaTime)
{
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void CreditsState::Draw()
{
	/*display the help image*/
	credits->pushToScreen(renderer, 0, 0);
}