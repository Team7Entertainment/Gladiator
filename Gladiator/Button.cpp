#include "button.h"

Button::Button(): Widget() {
	width = 0;
	height = 0;
	current = BUTTON_SPRITE_MOUSE_OUT;
}

Button::Button(int w, int h, int offset): Widget() {
	width = w;
	height = h;
	current = BUTTON_SPRITE_MOUSE_OUT;

	for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++) {
		sprites[i].x = offset;
		sprites[i].y = i * (height + 1);
		sprites[i].w = width;
		sprites[i].h = height;
	}
}

Button::Button(int w, int h, int offset, int x, int y): Widget(x, y) {
	width = w;
	height = h;
	current = BUTTON_SPRITE_MOUSE_OUT;

	for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++) {
		sprites[i].x = offset;
		sprites[i].y = i * (height + 1);
		sprites[i].w = width;
		sprites[i].h = height;
	}
}

void Button::handleEvent(SDL_Event* e) {
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < pos.x || x > pos.x + width) {
			inside = false;
		}
		else if (y < pos.y || y > pos.y + height) {
			inside = false;
		}

		if (!inside) {
			current = BUTTON_SPRITE_MOUSE_OUT;
		}
		else {
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

void Button::render(Texture* sheet) {
	sheet->render(pos.x, pos.y, &sprites[current]);
}

int Button::getCurrent() {
	return current;
}

bool Button::getClick() {
	return current == 3;
}