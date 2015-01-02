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
	numbers = new Texture("img/numbers42x42.bmp", renderer, true);

	/*initialize random seed: */
	srand((unsigned int)time(NULL));

	/*create a random background type between 0 and 2*/
	int backgroundType = rand() % 3;

	/*initialise entities*/
	background = new Background(backgrounds, backgroundType);
	player = new Player(spritesheet, 100.0f, 100.0f, 19, 0);

	/*load map*/
	map = new MapLoader("txt/map.txt", spritesheet, backgroundType);

	/*initialise collision*/
	collision = new Collision(player, map);

	/*initialise input commands*/
	cmdJump = cmdLeft = cmdRight = false;

	/*initialise player position bool*/
	centered = false;

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
	delete collision;
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
	tmp = deltaTime;
	/*tmp collision test*/
	//collision->playerCollisionTest(deltaTime, background->getX());

	/*tmp floor test*/
	if (player->getY() > (416.0f))
	{
		gravity = false;
		landed = true;
		player->setVelocityY(0.0f);
		player->setY(416.0f);
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
		updateScene(-100.0f);
	}
	/*if right go right*/
	if (cmdRight &!cmdLeft)
	{
		updateScene(100.0f);
	}
	/*if not right or left stay still*/
	if (!cmdRight &!cmdLeft)
	{
		updateScene(0.0f);
	}

	/*update gravity*/
	if (gravity)
	{
		player->setVelocityY(player->getVelocityY() + gravityF);
	}

	/*Update Background*/
	background->updateX(deltaTime);

	/*loop for the number of gems*/
	for (int i = 0; i < map->getNumberofGems(); i++)
	{
		/*update the gem*/
		map->getGem(i)->updateX(deltaTime);
	}

	/*loop for the number of blocks*/
	for (int i = 0; i < map->getNumberOfBlocks(); i++)
	{
		/*update the block*/
		map->getBlock(i)->updateX(deltaTime);
	}

	/*Update Player*/
	player->updateX(deltaTime);
	player->updateY(deltaTime);

	/*check if the player is centered*/
	if (player->getX() <= 310 && player->getX() >= 310 && background->getMoveable())
	{
		centered = true;
	}
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void GameState::Draw()
{
	/*display the background*/
	background->display(renderer);
	/*display the player*/
	player->display(renderer);
	/*Loop for the number of blocks*/
	for (int i = 0; i < map->getNumberOfBlocks(); i++)
	{
		/*display the block*/
		map->displayBlock(i, renderer);
	}	
	/*loop for the number of gems*/
	for (int i = 0; i < map->getNumberofGems(); i++)
	{
		/*check if the gem will be hidden*/
		if (!map->getGem(i)->getDeletable())
		{ 
			/*display the gem*/
			map->displayGem(i , renderer);
		}
	}
	/*display the score*/
	displayScore();
	collision->playerCollisionTest(tmp, background->getX(), spritesheet, renderer);
}

/**************************************************************************************************************/

/*draw the score to the screen*/
void GameState::displayScore()
{
	int currentScore = player->getScore();
	/*Loop for 5 digits*/
	for (int i = 0; i < 5; i++)
	{
		/*display the number*/
		numbers->pushSpriteToScreen(renderer, 32 * (5 - i), 32, 42 * (currentScore % 10), 0, 42, 42, 32, 32);
		currentScore = currentScore / 10;
	}
}

/**************************************************************************************************************/

/*update the scenes velocity using the inputed velocity*/
void GameState::updateScene(float velocity)
{
	if (centered && background->getMoveable())
	{
		background->setVelocity(-velocity);
		/*loop for the number of blocks*/
		for (int i = 0; i < map->getNumberOfBlocks(); i++)
		{
			/*set the blocks velocity*/
			map->getBlock(i)->setVelocity(-velocity);
		}
		/*loop for the number of gems*/
		for (int i = 0; i < map->getNumberofGems(); i++)
		{
			/*set the gems velocity*/
			map->getGem(i)->setVelocity(-velocity);
		}
	}
	else
	{
		centered = false;
		player->setVelocityX(velocity);
	}
}