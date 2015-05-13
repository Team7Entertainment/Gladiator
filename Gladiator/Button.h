#ifndef WID
#define WID
#include "Widget.h"
#endif

enum buttonTex {
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION,
	BUTTON_SPRITE_MOUSE_DOWN,
	BUTTON_SPRITE_MOUSE_UP,
	BUTTON_SPRITE_TOTAL
};

class Button: public Widget {
	public:
		Button();
		Button(int w, int h, int offset);
		Button(int w, int h, int offset, int x, int y);
		void handleEvent(SDL_Event* e);
		void render(Texture* sheet);
		int getCurrent();
		bool getClick();

	private:
		buttonTex current;
		SDL_Rect sprites[BUTTON_SPRITE_TOTAL];
};