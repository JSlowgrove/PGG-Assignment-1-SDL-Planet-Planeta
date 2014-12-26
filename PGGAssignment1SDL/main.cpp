#include <SDL.h>
#include <iostream>
#include <time.h>
#include "texture.h"
#include "building.h"
#include "turret.h"
#include "background.h"

void update(unsigned int &, SDL_Renderer *, Background *, float, float);

int main(int argc, char *argv[])
{
	/*Initialise SDL*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0) /*Check SDL initialisation*/
	{
		/*Failed initialisation*/
		std::cout << "Failed to initialise SDL" << std::endl;
		return -1;
	}

	/*initialize random seed: */
	srand(time(NULL));

	/*Time Check*/
	unsigned int lastTime = SDL_GetTicks();

	/*Create Window*/
	int winPosX = 100;
	int winPosY = 100;
	int winWidth = 640;
	int winHeight = 480;
	SDL_Window *window = SDL_CreateWindow("SDL Project",  /*The first parameter is the window title*/
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	/*Create Renderer from the window*/
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	/*initialise spritesheets*/
	Texture * backgrounds = new Texture("img/backgrounds231x63.bmp", renderer, false);
	Texture * spritesheet = new Texture("img/spritesheet21x21.bmp", renderer, true);

	/*initialise entities*/
	Background * background = new Background(backgrounds, (rand() % 3));
	Building * base = new Building(spritesheet, 0, 1);
	Building * power = new Building(spritesheet, 0, 2);
	Building * resource = new Building(spritesheet, 0, 5);
	Turret * turret = new Turret(spritesheet, 10, 1.5f, 0, 0);

	/*mouseClickPosition*/
	float x = 100.0f;
	float y = 100.0f;

	/*set Background velocity TMP*/
	background->setVelocity(-100.0f);

	/*Start Game Loop*/
	bool go = true;
	while (go)
	{
		/*Check for user input*/
		SDL_Event incomingEvent;
		while (SDL_PollEvent(&incomingEvent))
		{

			switch (incomingEvent.type)
			{
			case SDL_QUIT: /*If player closes the window end the game loop*/

				go = false;
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (incomingEvent.button.button == SDL_BUTTON_LEFT)
				{
					x = ((float) incomingEvent.motion.x) - 22;
					y = ((float) incomingEvent.motion.y) - 27;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				if (incomingEvent.button.button == SDL_BUTTON_LEFT)
				{
				}
				break;
			}
		}

		update(lastTime, renderer, background, x, y); /*Update the Window (pbRef, pbPointer)*/
	}
	/*uninitalise data*/
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}



/*Update Window (pbRef, pbPointer)*/
void update(unsigned int &lastTime, SDL_Renderer * renderer, Background * background, float x, float y)
{
	/*Time Check*/
	unsigned int current = SDL_GetTicks();
	float deltaTime = (float)(current - lastTime) / 1000.0f;
	lastTime = current;

	/*set draw colour to white*/
	SDL_SetRenderDrawColor(renderer, 0x00, 0x64, 0x00, 0x00);

	/*Clear the entire screen to the set colour*/
	SDL_RenderClear(renderer);

	/*Update Background*/
	background->updateX(deltaTime);

	/*display the background*/
	background->display(renderer);

	/*display renderer*/
	SDL_RenderPresent(renderer);

	/*Time Limiter*/
	if (deltaTime < (1.0f / 50.0f))
	{
		SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTime)*1000.0f));
	}
}