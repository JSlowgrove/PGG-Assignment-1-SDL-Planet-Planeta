#include <SDL.h>
#include <iostream>
#include "texture.h"

void update(unsigned int &, SDL_Renderer *);

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
			}
		}

		update(lastTime, renderer); /*Update the Window (pbRef, pbPointer)*/
	}
	/*uninitalise data*/
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}



/*Update Window (pbRef, pbPointer)*/
void update(unsigned int &lastTime, SDL_Renderer * renderer)
{
	/*Time Check*/
	unsigned int current = SDL_GetTicks();
	float deltaTs = (float)(current - lastTime) / 1000.0f;
	lastTime = current;

	/*set draw colour to white*/
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	/*Clear the entire screen to the set colour*/
	SDL_RenderClear(renderer);

	/*display renderer*/
	SDL_RenderPresent(renderer);

	/*Time Limiter*/
	if (deltaTs < (1.0f / 50.0f))
	{
		SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTs)*1000.0f));
	}
}