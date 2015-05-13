#ifndef MENU
#define MENU
#include "Menu.h"
#endif

class Options: public Menu {
	public:
		Options(SDL_Renderer* renderer);
		void initButtons();
		static const int VISUALS = 0;
		static const int AUDIO = 1;
		static const int CONTROLS = 2;
		static const int MOVES = 3;
		static const int MAIN_MENU = 4;
		const int BUTTON_NUM = 5;
};

class VisualOps : public Menu {
	public:
		VisualOps(SDL_Renderer* renderer);
		void initButtons();
		static const int RESOLUTION = 0;
		static const int GAMMA = 1;
		static const int QUALITY = 2;
		static const int OPTIONS = 3;
		const int BUTTON_NUM = 4;
};

class AudioOps : public Menu {
	public:
		AudioOps(SDL_Renderer* renderer);
		void initButtons();
		static const int MAIN_VOL = 0;
		static const int SFX_VOL = 1;
		static const int MUSIC_VOL = 2;
		static const int OPTIONS = 3;
		const int BUTTON_NUM = 4;
};

class ControlOps: public Menu {
	public:
		ControlOps(SDL_Renderer* renderer);
		void initButtons();
		static const int UP_MV = 0;
		static const int DOWN_MV = 1;
		static const int RIGHT_MV = 2;
		static const int LEFT_MV = 3;
		static const int LIGHT_ATK = 4;
		static const int HEAVY_ATK = 5;
		static const int SP_A = 6;
		static const int SP_B = 7;
		static const int OPTIONS = 8;
		const int BUTTON_NUM = 9;
};