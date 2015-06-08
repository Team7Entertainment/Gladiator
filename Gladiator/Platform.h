#ifndef TEX
#define TEX
#include "Texture.h"
#endif

class Platform {
	public:
		Platform();
		Platform(int x, int y, SDL_Rect spriteLoc);
		void update();
		void render(Texture* sheet);
		void scroll(int x, int y);

	private:
		int x;
		int y;
		int w;
		int h;
		SDL_Rect sprite;

};