#include "Texture.h"

class Widget {
	public:
		Widget();
		Widget(int x, int y);
		void setPosition(int x, int y);
		virtual void handleEvent(SDL_Event* e) = 0;
		virtual void render(Texture* sheet) = 0;
		virtual bool getClick() = 0;

	protected:
		int width;
		int height;
		bool mouseDown = false;
		SDL_Point pos;
};