#include "OptionMenu.h"

Options::Options(SDL_Renderer* renderer) : Menu(renderer) {
	sheet->loadFromFile("menuSheet.png");
	initButtons();
}

void Options::initButtons() {
	for (int i = 0; i < BUTTON_NUM; i++) {
		widgets.push_back(new Button(400, 50, i * 401));
		widgets[i]->setPosition(600, i * 51 + 300);
	}
}

VisualOps::VisualOps(SDL_Renderer* renderer) : Menu(renderer) {
	sheet->loadFromFile("menuSheet.png");
	initButtons();
}

void VisualOps::initButtons() {
	for (int i = 0; i < BUTTON_NUM; i++) {
		widgets.push_back(new Button(400, 50, i * 401));
		widgets[i]->setPosition(500, i * 51 + 300);
	}
}

AudioOps::AudioOps(SDL_Renderer* renderer) : Menu(renderer) {
	sheet->loadFromFile("menuSheet.png");
	initButtons();
}

void AudioOps::initButtons() {
	for (int i = 0; i < BUTTON_NUM; i++) {
		widgets.push_back(new Button(400, 50, i * 401));
		widgets[i]->setPosition(400, i * 51 + 300);
	}
}

ControlOps::ControlOps(SDL_Renderer* renderer) : Menu(renderer) {
	sheet->loadFromFile("menuSheet.png");
	initButtons();
}

void ControlOps::initButtons() {
	for (int i = 0; i < BUTTON_NUM; i++) {
		widgets.push_back(new Button(300, 50, i * 401));
		widgets[i]->setPosition(500, i * 51 + 300);
	}
}