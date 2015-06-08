#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "MenuSystem.h"
#include "GameSystem.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//Starts up SDL and creates window
void init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

//The window renderer
SDL_Renderer* renderer = NULL;

void init() {
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	SDL_DisplayMode *disp = new SDL_DisplayMode();
	SDL_GetCurrentDisplayMode(0, disp);

	//Create window
	gWindow = SDL_CreateWindow("Glatiator Pre-Alpha 0.0", 10, 37, disp->w-20, disp->h-92, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	//Create vsynced renderer for window
	renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void close() {
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[]) {
	//Start up SDL and create window
	init();

	MenuSystem menus = MenuSystem(renderer);
	GameSystem game = GameSystem(renderer);

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit) {
		SDL_RenderClear(renderer);

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT || menus.getQuit())
			{
				quit = true;
			}
			menus.update(&e);
		}

		menus.update(&e);
		game.update(&e, menus.getPaused());

		//Update the surface
		SDL_RenderPresent(renderer);
		Sleep(10);
	}

	//Free resources and close SDL
	close();

	return 0;
}