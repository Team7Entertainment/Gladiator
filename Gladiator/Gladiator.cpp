//#include <SDL.h>
//#include <SDL_image.h>
#include "MainMenu.h"
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//Starts up SDL and creates window
void init();

//Loads media
void loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

void init() {
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;

	//Create vsynced renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Get window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);
}

void loadMedia() {
	//Load PNG surface
	gPNGSurface = loadSurface("loaded.png");
}

void close() {
	//Free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	//Convert surface to screen format
	optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);

	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);

	return optimizedSurface;
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	init();

	//Load media
	loadMedia();
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Apply the PNG image
		SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, NULL);

		//Update the surface
		SDL_UpdateWindowSurface(gWindow);
	}

	//Free resources and close SDL
	close();

	return 0;
}