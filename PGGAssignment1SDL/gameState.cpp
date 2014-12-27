#include "gameState.h"
#include "menuState.h"

/**************************************************************************************************************/

/*Constructs the menu state object*/
GameState::GameState(StateManager * inStateManager, SDL_Renderer* inRenderer) : State(inStateManager, inRenderer)
{
	/*set state name*/
	name = "game";
	/*initialise spritesheets*/
	backgrounds = new Texture("img/backgrounds231x63.bmp", renderer, false);
	spritesheet = new Texture("img/spritesheet21x21.bmp", renderer, true);
	/*initialise entities*/
	background = new Background(backgrounds, (rand() % 3));
	player = new Player(spritesheet, 100.0f, 100.0f, 19, 0);
	/*initialise gems*/
	gems.resize(4);
	gems[0] = new Gem(spritesheet, 300.0f, 100.0f, 16, 12, 0);
	gems[1] = new Gem(spritesheet, 400.0f, 100.0f, 16, 12, 1);
	gems[2] = new Gem(spritesheet, 500.0f, 100.0f, 16, 12, 2);
	gems[3] = new Gem(spritesheet, 600.0f, 100.0f, 16, 12, 3);
	/*initialise blocks*/
	blocks.resize(4);
	blocks[0] = new Block(spritesheet, 100.0f, 400.0f, 3, 0, 0);
	blocks[1] = new Block(spritesheet, 200.0f, 400.0f, 5, 0, 0);
	blocks[2] = new Block(spritesheet, 300.0f, 400.0f, 2, 1, 0);
	blocks[3] = new Block(spritesheet, 400.0f, 400.0f, 3, 1, 0);
	/*initialize random seed: */
	srand((unsigned int)time(NULL));

	/*initialise input commands*/
	cmdJump = cmdLeft = cmdRight = false;

	/*set Background velocity TMP*/
	background->setVelocity(-100.0f);

	/*initialise tmp jump vars*/
	gravity = true;
	landed = false;
	jump = false;
	gravityF = 9.81f;
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
	for (int i = 0; i < gems.size(); i++)
	{
		delete gems.at(i);
	}
	for (int i = 0; i < blocks.size(); i++)
	{
		delete blocks.at(i);
	}
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
			/*If space is pressed*/
			case SDLK_SPACE:
				/*jump is true*/
				cmdJump = true;
				break;
			/*If left is pressed*/
			case SDLK_LEFT:
				/*set left true*/
				cmdLeft = true;
				break;
			/*If right is pressed*/
			case SDLK_RIGHT:
				/*set right true*/
				cmdRight = true;
				break;
			/*If A is pressed*/
			case SDLK_a:
				/*set left true*/
				cmdLeft = true;
				break;
			/*If D is pressed*/
			case SDLK_d:
				/*set right true*/
				cmdRight = true;
				break;
			}
			break;

		case SDL_KEYUP:/*If a key is released*/

			switch (incomingEvent.key.keysym.sym)
			{
				/*If space is released*/
			case SDLK_SPACE:
				/*jump is false*/
				cmdJump = false;
				break;
				/*If left is released*/
			case SDLK_LEFT:
				/*set left false*/
				cmdLeft = false;
				break;
				/*If right is released*/
			case SDLK_RIGHT:
				/*set right false*/
				cmdRight = false;
				break;
				/*If A is released*/
			case SDLK_a:
				/*set left false*/
				cmdLeft = false;
				break;
				/*If D is released*/
			case SDLK_d:
				/*set right false*/
				cmdRight = false;
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
	/*tmp floor test*/
	if (player->getY() >= (400.0f))
	{
		gravity = false;
		landed = true;
		player->setVelocityY(0.0f);
		player->setY(400.0f);
	}
	else
	{
		landed = false;
		gravity = true;
	}

	/*if able to jump, jump*/
	if (cmdJump && landed)
	{
		gravity = false;
		player->setVelocityY(-350.0f);
	}
	/*if left go left*/
	if (cmdLeft &!cmdRight)
	{
		background->setVelocity(100.0f);
		player->setVelocityX(-100.0f);
	}
	/*if right go right*/
	if (cmdRight &!cmdLeft)
	{
		background->setVelocity(-100.0f);
		player->setVelocityX(100.0f);
	}
	/*if not right or left stay still*/
	if (!cmdRight &!cmdLeft)
	{
		background->setVelocity(0.0f);
		player->setVelocityX(0.0f);
	}

	/*update gravity*/
	if (gravity)
	{
		player->setVelocityY(player->getVelocityY() + gravityF);
	}

	/*Update Background*/
	background->updateX(deltaTime);

	/*Update Player*/
	player->updateX(deltaTime);
	player->updateY(deltaTime);
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void GameState::Draw()
{
	/*display the background*/
	background->display(renderer);
	/*display the player*/
	player->display(renderer);
	/*display the gems*/
	for (int i = 0; i < gems.size(); i++)
	{
		gems[i]->display(renderer);
	}
	/*display the blocks*/
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->display(renderer);
	}
}