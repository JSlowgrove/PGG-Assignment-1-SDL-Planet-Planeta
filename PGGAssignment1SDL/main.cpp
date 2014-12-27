#include <SDL.h>
#include <iostream>
#include "texture.h"
#include "stateManager.h"
#include "menuState.h"

int main(int argc, char *argv[])
{
	/*Initialise SDL*/
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
	SDL_Window *window = SDL_CreateWindow("Planet Planeta",  /*The first parameter is the window title*/
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	/*Create Renderer from the window*/
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	
	/*setup state manager*/
	StateManager * stateManager = new StateManager();
	stateManager->AddState(new MenuState(stateManager, renderer));

	/*Start Game Loop*/
	bool go = true;
	while (go)
	{
		
		/*Time Check*/
		unsigned int current = SDL_GetTicks();
		float deltaTime = (float)(current - lastTime) / 1000.0f;
		lastTime = current;

		//handle the current states SDL Events (if state SDL is exit then go is set to false)
		go = stateManager->HandleSDLEvents();

		//update the current state
		stateManager->Update(deltaTime);

		/*set draw colour to white*/
		SDL_SetRenderDrawColor(renderer, 0x00, 0x64, 0x00, 0x00);

		/*Clear the entire screen to the set colour*/
		SDL_RenderClear(renderer);

		//draw the current state
		stateManager->Draw();

		/*display renderer*/
		SDL_RenderPresent(renderer);

		/*Time Limiter*/
		if (deltaTime < (1.0f / 50.0f))
		{
			SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTime)*1000.0f));
		}
	}
	/*destroy data*/
	delete stateManager;
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
