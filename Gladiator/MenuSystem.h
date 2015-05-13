#include "MainMenu.h"
#include "OptionMenu.h"

class MenuSystem {
	public:
		MenuSystem(SDL_Renderer* renderer);
		void update(SDL_Event* e);
		bool getQuit();
		bool getPaused();
		void toFrom(Menu* first, Menu* second);

	private:
		MainMenu* mainM;
		Options* options;
		VisualOps* visual;
		SDL_Renderer* renderer;
		bool quit = false;
		bool pause = true;
};