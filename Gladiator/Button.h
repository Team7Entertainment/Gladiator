#ifndef TEX
#define TEX
#include "Texture.h"
#endif

enum buttonTex {
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION,
	BUTTON_SPRITE_MOUSE_DOWN,
	BUTTON_SPRITE_MOUSE_UP,
	BUTTON_SPRITE_TOTAL
};

class Button {
	public:
		Button();
		Button(int w, int h, int offset);
		void setPosition(int x, int y);
		void handleEvent(SDL_Event* e);
		void render(Texture sheet);

	private:
		int width;
		int height;
		bool mouseDown = false;
		SDL_Point pos;
		buttonTex current;
		SDL_Rect sprites[BUTTON_SPRITE_TOTAL];
};

Button::Button() {
	width = 0;
	height = 0;
	pos.x = 0;
	pos.y = 0;
	current = BUTTON_SPRITE_MOUSE_OUT;
}

Button::Button(int w, int h, int offset) {
	width = w;
	height = h;
	pos.x = 0;
	pos.y = 0;
	current = BUTTON_SPRITE_MOUSE_OUT;

	for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++) {
		sprites[i].x = offset;
		sprites[i].y = i * height;
		sprites[i].w = width;
		sprites[i].h = height;
	}
}

void Button::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;
}

void Button::handleEvent(SDL_Event* e) {
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < pos.x || x > pos.x + width) {
			inside = false;
		} else if (y < pos.y || y > pos.y + height) {
			inside = false;
		}

		if (!inside) {
			current = BUTTON_SPRITE_MOUSE_OUT;
		} else {
			//Set mouse over sprite
			switch (e->type) {
			case SDL_MOUSEMOTION:
				if (!mouseDown) {
					current = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseDown = true;
				current = BUTTON_SPRITE_MOUSE_DOWN;
				break;
			case SDL_MOUSEBUTTONUP:
				mouseDown = false;
				current = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}

void Button::render(Texture sheet) {
	sheet.render(pos.x, pos.y, &sprites[current]);
}