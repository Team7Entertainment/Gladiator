#ifndef WID
#define WID
#include "Widget.h"
#endif

class Slider: public Widget{
	public:
		Slider();
		Slider(int w, int h, int offset);
		Slider(int w, int h, int offset, int x, int y);
		void handleEvent(SDL_Event* e);
		void render(Texture* sheet);
		bool getClick();

	private:
		SDL_Rect rail;
		SDL_Rect handle;
		SDL_Point handlePos;
};