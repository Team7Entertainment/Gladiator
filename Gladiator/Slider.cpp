#include "Slider.h"

Slider::Slider(): Widget() {
	width = 0;
	height = 0;
	handlePos.x = 0;
	handlePos.y = 0;
}

Slider::Slider(int w, int h, int offset) : Widget() {
	width = w;
	height = h;
	handlePos.x = 0;
	handlePos.y = 0;
	
	rail.x = offset;
	rail.y = 0;
	rail.w = w;
	rail.h = h;

	handle.x = offset + w + 1;
	handle.y = 0;
	handle.w = 20;
	handle.h = h;
}

Slider::Slider(int w, int h, int offset, int x, int y) : Widget(x, y) {
	width = w;
	height = h;
	handlePos.x = x + 20;
	handlePos.y = y;

	rail.x = offset;
	rail.y = 0;
	rail.w = w;
	rail.h = h;

	handle.x = offset + w + 1;
	handle.y = 0;
	handle.w = 20;
	handle.h = h;
}

void Slider::handleEvent(SDL_Event* e) {
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

		switch (e->type) {
		case SDL_MOUSEMOTION:
			if (mouseDown) handlePos.x = x - 10;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (inside) mouseDown = true;
			if (mouseDown) handlePos.x = x - 10;
			break;
		case SDL_MOUSEBUTTONUP:
			mouseDown = false;
			break;
		}

		if (handlePos.x < pos.x + 20) handlePos.x = pos.x + 20;
		if (handlePos.x > pos.x + width - 20) handlePos.x = pos.x + width - 20;
	}
}

void Slider::render(Texture* sheet) {
	sheet->render(pos.x, pos.y, &rail);
	sheet->render(handlePos.x, handlePos.y, &handle);
}

bool Slider::getClick() {
	return mouseDown;
}