#include <SDL.h>
#include <iostream>
#include "texture.h"
#include "minion.h"
#include "building.h"
#include "turret.h"

void update(unsigned int &, SDL_Renderer *, Minion *, Minion *, Turret *, Building *, Building *, Building *, float, float);

int main(int argc, char *argv[])
{
	/*Initilise SDL*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0) /*Check SDL initialisation*/
	{
		/*Failed initialisation*/
		std::cout << "Failed to initialise SDL" << std::endl;
		return -1;
	}

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

	/*initalise spritesheet*/
	Texture * spritesheet = new Texture("img/spritesheet88x108.bmp", renderer, true);

	/*intalise entities*/
	Building * base = new Building(spritesheet, 0, 1);
	Building * power = new Building(spritesheet, 0, 2);
	Building * resource = new Building(spritesheet, 0, 5);
	Minion * engineer = new Minion(spritesheet, 10, 200.0f, 1.5f, 0, 3);
	Minion * soldier = new Minion(spritesheet, 10, 200.0f, 1.5f, 0, 4);
	Turret * turret = new Turret(spritesheet, 10, 1.5f, 0, 0);

	/*mouseClickPosition*/
	float x = 100.0f;
	float y = 100.0f;

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

		update(lastTime, renderer, engineer, soldier, turret, base, power, resource, x, y); /*Update the Window (pbRef, pbPointer)*/
	}
	/*uninitalise data*/
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}



/*Update Window (pbRef, pbPointer)*/
void update(unsigned int &lastTime, SDL_Renderer * renderer, Minion * engineer, Minion * soldier, Turret * turret, Building * base, Building * power, Building * resource, float x, float y)
{
	/*Time Check*/
	unsigned int current = SDL_GetTicks();
	float deltaTs = (float)(current - lastTime) / 1000.0f;
	lastTime = current;

	/*set draw colour to white*/
	SDL_SetRenderDrawColor(renderer, 0x00, 0x64, 0x00, 0x00);

	/*Clear the entire screen to the set colour*/
	SDL_RenderClear(renderer);
	
	/*set inital positions TEMP*/
	power->setX(300.0f);
	power->setY(300.0f);
	resource->setX(300.0f);
	resource->setY(100.0f);
	base->setX(200.0f);
	base->setY(200.0f);
	engineer->setX(x);
	engineer->setY(y);
	soldier->setX(100.0f);
	soldier->setY(300.0f);
	turret->setX(400.0f);
	turret->setY(400.0f);

	/*push entities to the renderer*/
	power->display(renderer);
	resource->display(renderer);
	base->display(renderer);
	engineer->display(renderer);
	soldier->display(renderer);
	turret->display(renderer);

	/*display renderer*/
	SDL_RenderPresent(renderer);

	/*Time Limiter*/
	if (deltaTs < (1.0f / 50.0f))
	{
		SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTs)*1000.0f));
	}
}