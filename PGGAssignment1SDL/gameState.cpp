#include "gameState.h"
#include "menuState.h"
#include "helpState.h"
#include "winLoseState.h"

/**************************************************************************************************************/

/*Constructs the game state object*/
GameState::GameState(StateManager * inStateManager, SDL_Renderer* inRenderer) : State(inStateManager, inRenderer)
{
	/*set state name*/
	name = "game";
	/*initialise spritesheets*/
	backgrounds = new Texture("img/backgrounds231x63.bmp", renderer, false);
	spritesheet = new Texture("img/spritesheet21x21.bmp", renderer, true);
	numbers = new Texture("img/numbers42x42.bmp", renderer, true);
	gameKeys = new Texture("img/gameKeys197x40.bmp", renderer, true);

	/*initialise and start the music*/
	lifeLost = new Audio("aud/jingles_PIZZA05.ogg", false);
	gemPickup = new Audio("aud/powerUp6.ogg", false);
	music = new Audio("aud/Electrodoodle.mp3", true);
	music->startAudio();

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
	collision = new Collision(player, map, background, gemPickup, lifeLost);

	/*initialise input commands*/
	cmdJump = cmdLeft = cmdRight = false;

	/*initialise player position bool*/
	centered = false;

}

/**************************************************************************************************************/

/*destructs the game state object*/
GameState::~GameState()
{
	/*stop music*/
	music->stopAudio();
	/*delete audio pointers*/
	delete music;
	delete gemPickup;
	delete lifeLost;
	/*delete entity pointers*/
	delete player;
	delete background;
	delete map;
	/*delete collision pointer*/
	delete collision;
	/*delete texture pointer*/
	delete backgrounds;
	delete spritesheet;
	delete numbers;
	delete gameKeys;
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
				/*set all commands to false*/
				cmdJump = cmdLeft = cmdRight = false;
				/*open up the help*/
				stateManager->AddState(new HelpState(stateManager, renderer));
				break;
				/*if delete is pressed*/
			case SDLK_DELETE:
				/*return to the menu*/
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
	/*check the music is still playing if not start again*/
	music->startAudio();

	/*check if the player is centered*/
	if (player->getX() <= 302 && player->getX() >= 298)
	{
		/*check if the player is going left, is centered and the background cant go any further to the right*/
		if (cmdLeft && !background->getRightMoveable() && centered)
		{
			/*the player is not centered so it can move around the left side of the screen*/
			centered = false;
		}
		/*check if the player is going right, is centered and the background cant go any further to the left*/
		else if (cmdRight && !background->getLeftMoveable() && centered)
		{
			/*the player is not centered so it can move around the right side of the screen*/
			centered = false;
		}
		/*the screen can move so the player doesn't*/
		else
		{
			centered = true;
		}
	}
	/*x axis collision tests*************************/
	/*loop for the number of enemies*/
	for (int i = 0; i < map->getNumberOfEnemies(); i++)
	{
		if (map->getEnemy(i)->getSpeed() != 0)
		{
			/*test the enemy collision*/
			collision->enemyCollision(i, deltaTime);
		}
	}

	/*if left go left*/
	if (cmdLeft &!cmdRight)
	{
		updateScene(-200.0f, background->getRightMoveable());
	}
	/*if right go right*/
	if (cmdRight &!cmdLeft)
	{
		updateScene(200.0f, background->getLeftMoveable());
	}
	/*if not right or left stay still*/
	if (!cmdRight &!cmdLeft)
	{
		updateScene(0.0f, background->getMoveable());
	}
	/*check collisions*/
	collision->playerCollisionTest(deltaTime, 'x');

	/*check if player is off the screen on the x axis to the left*/
	if ((player->getX() + (player->getVelocityX() * deltaTime)) <= 0)
	{
		/*keep on screen*/
		player->setVelocityX(0.0f);
		player->setX(1.0f);
	}
	/*check if player is off the screen on the x axis to the right*/
	if ((player->getX() + (player->getVelocityX() * deltaTime)) + 32 >= 640)
	{
		/*keep on screen*/
		player->setVelocityX(0.0f);
		player->setX(607.0f);
	}

	/*y axis collision tests*************************/
	/*set as if not colliding down*/
	player->setLanded(false);
	player->setGravity(true);

	/*check collisions*/
	collision->playerCollisionTest(deltaTime, 'y');

	/*if able to jump, jump*/
	if (cmdJump && player->getLanded())
	{
		player->setLanded(false);
		player->setGravity(false);
		player->setVelocityY(-450.0f);
	}
	/*update gravity*/
	if (player->getGravity())
	{
		player->setVelocityY(player->getVelocityY() + player->getGravityF());
	}

	/*check if player is off the screen on the y axis up*/
	if ((player->getY() + (player->getVelocityY() * deltaTime)) <= 0)
	{
		/*keep on screen*/
		player->setVelocityY(0.0f);
		player->setY(1.0f);
	}

	/*check if player is off the screen on the y axis down*/
	if ((player->getY() + (player->getVelocityY() * deltaTime)) + 32 >= 480)
	{
		/*keep on screen*/
		player->setVelocityY(0.0f);
		player->setY(1.0f);
		player->setLives(player->getScore() - 1);
	}

	/*update all positions***************************/
	/*Update Background*/
	background->updateX(deltaTime);

	/*loop for the number of gems*/
	for (int i = 0; i < map->getNumberOfGems(); i++)
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
	/*fixes the bug that causes the enemy to shift on camera switch*/
	if (background->getMoveable())
	{
		/*loop for the number of enemies*/
		for (int i = 0; i < map->getNumberOfEnemies(); i++)
		{
			/*update the enemy*/
			map->getEnemy(i)->updateX(deltaTime);
		}
	}

	/*player enemy test*/
	collision->playerCreatureCollisionTest(deltaTime);

	/*Update Player*/
	player->updateX(deltaTime);
	player->updateY(deltaTime);

	/*test if the player has won the level, if so open win*/
	if (player->getLevelComplete())
	{
		/*change to the win screen*/
		stateManager->ChangeState(new WinLoseState(stateManager, renderer, true, player->getScore()));
	}
	/*test if the player has lost all their lives*/
	else if (player->getLives() <= 0)
	{
		/*change to the lose screen*/
		stateManager->ChangeState(new WinLoseState(stateManager, renderer, false, player->getScore()));
	}
}

/**************************************************************************************************************/

/*draw the state to the screen*/
void GameState::Draw()
{
	/*display the background*/
	background->display(renderer);
	/*Loop for the number of blocks*/
	for (int i = 0; i < map->getNumberOfBlocks(); i++)
	{
		/*display the block*/
		map->displayBlock(i, renderer);
	}	
	/*loop for the number of gems*/
	for (int i = 0; i < map->getNumberOfGems(); i++)
	{
		/*check if the gem will be hidden*/
		if (!map->getGem(i)->getDeletable())
		{ 
			/*display the gem*/
			map->displayGem(i , renderer);
		}
	}
	/*loop for the number of enemies*/
	for (int i = 0; i < map->getNumberOfEnemies(); i++)
	{
		/*check if the gem will be hidden*/
		if (!map->getEnemy(i)->getDeletable())
		{
			/*display the enemy*/
			map->displayEnemy(i, renderer);
		}
	}
	/*display the score*/
	displayScore();
	/*display the number of lives the player has left*/
	for (int i = 1; i <= player->getLives(); i++)
	{
		/*display a heart to the screen*/
		spritesheet->pushSpriteToScreen(renderer, 32 * (1 + i), 64, 301, 278, 21, 21, 32, 32);
	}
	/*display the help game key*/
	gameKeys->pushSpriteToScreen(renderer, 32 * 8, 32, 0, 0, 197, 40, 157, 32);
	/*display the quit game key*/
	gameKeys->pushSpriteToScreen(renderer, 32 * 14, 32, 0, 40, 197, 40, 157, 32);
	/*display the player*/
	player->display(renderer);
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
void GameState::updateScene(float velocity, bool moveable)
{
	/*if the map should move not the player*/
	if (centered && moveable)
	{
		background->setVelocity(-velocity);
		/*loop for the number of blocks*/
		for (int i = 0; i < map->getNumberOfBlocks(); i++)
		{
			/*set the blocks velocity*/
			map->getBlock(i)->setVelocity(-velocity);
		}
		/*loop for the number of gems*/
		for (int i = 0; i < map->getNumberOfGems(); i++)
		{
			/*set the gems velocity*/
			map->getGem(i)->setVelocity(-velocity);
		}
		if (background->getMoveable())
		{
			/*loop for the number of enemies*/
			for (int i = 0; i < map->getNumberOfEnemies(); i++)
			{
				/*set the enemies velocity*/
				map->getEnemy(i)->setVelocityX(-velocity);
			}
		}
		player->setVelocityX(0.0f);
	}
	/*if the player should move not the map*/
	else
	{
		player->setVelocityX(velocity);
		/*loop for the number of enemies*/
		for (int i = 0; i < map->getNumberOfEnemies(); i++)
		{
			/*set the enemies velocity*/
			map->getEnemy(i)->setVelocityX(0.0f);
		}
	}
	/*move the enemies*/
	for (int i = 0; i < map->getNumberOfEnemies(); i++)
	{
		/*set the enemies velocity*/
		map->getEnemy(i)->setVelocityX(map->getEnemy(i)->getVelocityX() + map->getEnemy(i)->getSpeed());
	}
}