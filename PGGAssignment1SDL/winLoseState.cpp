#include "winLoseState.h"
#include "menuState.h"
#include "gameState.h"

/**************************************************************************************************************/

/*Constructs the win lose state object*/
WinLoseState::WinLoseState(StateManager * inStateManager, SDL_Renderer* inRenderer, bool inWin, int inScore) : State(inStateManager, inRenderer)
{
	/*set state name*/
	name = "winLose";
	/*declare the texture for the background*/
	background = new Texture("img/menu.bmp", renderer, false);
	/*declare the texture for the keys and numbers*/
	winLoseKeys = new Texture("img/winLoseKeys351x30.bmp", renderer, true);
	afterWinLoseKey = new Texture("img/afterWinLoseKey612x205.bmp", renderer, true);
	numbers = new Texture("img/numbers42x42.bmp", renderer, true);
	/*declare the win bool*/
	win = inWin;
	/*declare the score*/
	score = inScore;
}

/**************************************************************************************************************/

/*destructs the win lose state object*/
WinLoseState::~WinLoseState()
{
	/*delete pointers*/
	delete background;
	delete winLoseKeys;
	delete afterWinLoseKey;
	delete numbers;
}

/**************************************************************************************************************/

/*handle the SDL events*/
bool WinLoseState::HandleSDLEvents()
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
				/*go to menu*/
				stateManager->ChangeState(new MenuState(stateManager, renderer));
				break;
			/*if delete is pressed*/
			case SDLK_RETURN:
				/*play again*/
				stateManager->ChangeState(new GameState(stateManager, renderer));
				break;
			}
			break;
		}
	}
	return true;
}

/**************************************************************************************************************/

/*update the state*/
void WinLoseState::Update(float deltaTime)
{
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void WinLoseState::Draw()
{
	/*display the background*/
	background->pushToScreen(renderer, 0, 0);
	if (win)
	{
		/*display the play key*/
		winLoseKeys->pushSpriteToScreen(renderer, 154, 170, 0, 30, 351, 30);
	}
	else
	{
		/*display the credits key*/
		winLoseKeys->pushSpriteToScreen(renderer, 154, 170, 0, 0, 351, 30);
	}
	/*display the exit key*/
	afterWinLoseKey->pushSpriteToScreen(renderer, 14, 240, 0, 0, 612, 205);
	/*display the score*/
	displayScore();
}

/**************************************************************************************************************/

/*draw the score to the screen*/
void WinLoseState::displayScore()
{
	int currentScore = score;
	/*Loop for 5 digits*/
	for (int i = 0; i < 5; i++)
	{
		/*display the number*/
		numbers->pushSpriteToScreen(renderer, 322 + (30 * (5 - i)), 240, 42 * (currentScore % 10), 0, 42, 42, 30, 30);
		currentScore = currentScore / 10;
	}
}