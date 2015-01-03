#include "menuState.h"
#include "gameState.h"
#include "creditsState.h"

/**************************************************************************************************************/

/*Constructs the menu state object*/
MenuState::MenuState(StateManager * inStateManager, SDL_Renderer* inRenderer) : State(inStateManager, inRenderer)
{
	/*set state name*/
	name = "menu";
	/*set default mouse current position*/
	x = 0.0f;
	y = 0.0f;
	/*declare the texture for the background*/
	background = new Texture("img/menu.bmp", renderer, false);
	/*declare the texture for the menu keys*/
	menuKeys = new Texture("img/menuKeys205x35.bmp", renderer, true);
	/*set the keys to 0*/
	playKey = 0;
	credKey = 0;
	exitKey = 0;
	/*set to not pressed*/
	pressed = 0;
}

/**************************************************************************************************************/

/*destructs the menu state object*/
MenuState::~MenuState()
{
	/*delete pointers*/
	delete background;
	delete menuKeys;
}

/**************************************************************************************************************/

/*handle the SDL events*/
bool MenuState::HandleSDLEvents()
{
	/*Check for user input*/
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		x = ((float)incomingEvent.motion.x);
		y = ((float)incomingEvent.motion.y);

		/*a ternary operator checking if the mouse is above the play key*/
		playKey = (x > 131 && x < 255 && y > 200 && y < 235) ? 1 : 0;
		/*a ternary operator checking if the mouse is above the credits key*/
		credKey = (x > 90 && x < 295 && y > 260 && y < 295) ? 1 : 0;
		/*a ternary operator checking if the mouse is above the exit key*/
		exitKey = (x > 138 && x < 248 && y > 320 && y < 355) ? 1 : 0;

		switch (incomingEvent.type)
		{
		case SDL_QUIT: /*If player closes the window end the game loop*/

			return false;
			break;

		case SDL_MOUSEBUTTONDOWN: /*If the mouse is pressed*/
			/*if the left mouse button set the x and y to the current mouse position*/
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{
				/*if play key is highlighted*/
				if (playKey == 1)
				{
					/*set pressed to 1*/
					pressed = 1;
				}

				/*if credits key is highlighted*/
				if (credKey == 1)
				{
					/*set pressed to 2*/
					pressed = 2;
				}

				/*if exit key is highlighted*/
				if (exitKey == 1)
				{
					/*set pressed to 3*/
					pressed = 3;
				}

				/*if no key is highlighted*/
				if (playKey == 0 && credKey == 0 && exitKey == 0)
				{
					/*set pressed to 0*/
					pressed = 0;
				}
			}
			break;

		case SDL_MOUSEBUTTONUP:/*If the mouse is released*/
			/*if the left mouse button*/
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{
				switch (pressed)
				{
				case 1:
					/*go to the game state*/
					stateManager->ChangeState(new GameState(stateManager, renderer));
					break;
				case 2:
					/*open up the credits*/
					stateManager->AddState(new CreditsState(stateManager, renderer));
					break;
				case 3:
					/*exit the application*/
					return false;
					break;
				}
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
	background->pushToScreen(renderer, 0, 0);
	/*display the play key*/
	menuKeys->pushSpriteToScreen(renderer, 90, 200, (205 * playKey), 0, 205, 35);
	/*display the credits key*/
	menuKeys->pushSpriteToScreen(renderer, 90, 260, (205 * credKey), 35, 205, 35);
	/*display the exit key*/
	menuKeys->pushSpriteToScreen(renderer, 90, 320, (205 * exitKey), 70, 205, 35);
}