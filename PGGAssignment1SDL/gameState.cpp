#include "gameState.h"
#include "menuState.h"

/**************************************************************************************************************/

/*Constructs the menu state object*/
GameState::GameState(StateManager * inStateManager, SDL_Renderer* renderer)	: State(inStateManager, renderer)
{
	/*set state name*/
	name = "game";
	/*initialise spritesheets*/
	backgrounds = new Texture("img/backgrounds231x63.bmp", renderer, false);
	spritesheet = new Texture("img/spritesheet21x21.bmp", renderer, true);
	/*initialise entities*/
	background = new Background(backgrounds, (rand() % 3));
	player = new Player(spritesheet, 100.0f, 100.0f, 19, 0);
	/*initialize random seed: */
	srand((unsigned int)time(NULL));

	/*set Background velocity TMP*/
	background->setVelocity(-100.0f);
}

/**************************************************************************************************************/

/*destructs the menu state object*/
GameState::~GameState()
{
	/*delete pointers*/
	delete player;
	delete background;
	delete backgrounds;
	delete spritesheet;
}

/**************************************************************************************************************/

/*handle the SDL events*/
bool GameState::HandleSDLEvents()
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
				/*change the state to the menu state*/
				stateManager->ChangeState(new MenuState(stateManager, renderer));
				break;
			/*If A is pressed*/
			case SDLK_a:
				/*change the players x velocity so it goes to the left*/
				player->setVelocityX(-100.0f);
				break;
			/*If D is pressed*/
			case SDLK_d:
				/*change the players x velocity so it goes to the right*/
				player->setVelocityX(100.0f);
				break;
			}
			break;

		case SDL_KEYUP:/*If a key is released*/

			switch (incomingEvent.key.keysym.sym)
			{
			/*If A is released*/
			case SDLK_a:
				/*set the player velocity to 0 so the player stops moving*/
				player->setVelocityX(0.0f);
				break;
			/*If D is released*/
			case SDLK_d:
				/*set the player velocity to 0 so the player stops moving*/
				player->setVelocityX(0.0f);
				break;
			}

			break;
		}
	}
	return true;
}

/**************************************************************************************************************/

/*update the state*/
void GameState::Update(float deltaTime)
{
	/*Update Background*/
	background->updateX(deltaTime);
	/*Update Player*/
	player->updateX(deltaTime);
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void GameState::Draw()
{
	/*display the background*/
	background->display(renderer);
	/*display the player*/
	player->display(renderer);
}