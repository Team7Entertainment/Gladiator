#ifndef MENU
#define MENU
#include "Menu.h"
#endif

class MainMenu: public Menu{
	public:
		MainMenu(SDL_Renderer* renderer);
		void initButtons();
		static const int SINGLEPLAYER = 0;
		static const int ARCADE = 1;
		static const int MULTIPLAYER = 2;
		static const int OPTIONS = 3;
		static const int QUIT = 4;
		static const int BUTTON_NUM = 5;
};