#include "helpState.h"

/**************************************************************************************************************/

/*Constructs the help state object*/
HelpState::HelpState(StateManager * inStateManager, SDL_Renderer* inRenderer) : State(inStateManager, inRenderer)
{
	/*declare the texture for the help screen*/
	help = new Texture("img/help.bmp", renderer, true);
}

/**************************************************************************************************************/

/*destructs the help state object*/
HelpState::~HelpState()
{
	/*delete pointers*/
	delete help;
}

/**************************************************************************************************************/

/*handle the SDL events*/
bool HelpState::HandleSDLEvents()
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
				/*return to the game*/
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
void HelpState::Update(float deltaTime)
{
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void HelpState::Draw()
{
	/*display the help image*/
	help->pushToScreen(renderer, 0, 0);
}