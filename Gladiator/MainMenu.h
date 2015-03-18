#ifndef TEX
#define TEX
#include "Texture.h"
#endif
#include "Button.h"

const int BUTTON_NUM = 4;

class MainMenu {
	public:
		MainMenu(SDL_Renderer* renderer);
		void update(SDL_Event* e);
		void handleMouse(SDL_Event* e);

	private:
		Texture sheet = Texture();
		Button buttons[BUTTON_NUM];
};

MainMenu::MainMenu(SDL_Renderer* renderer) {
	sheet.setRenderer(renderer);
	sheet.loadFromFile("menuSheet.png");
	for (int i = 0; i < BUTTON_NUM; i++) {
		buttons[i] = Button(400, 50, i * 400 + 1);
		buttons[i].setPosition(600, i * 51);
	}
}

void MainMenu::update(SDL_Event* e) {
	handleMouse(e);
	for (int i = 0; i < BUTTON_NUM; i++) {
		buttons[i].render(sheet);
	}
}

void MainMenu::handleMouse(SDL_Event* e) {
	for (int i = 0; i < BUTTON_NUM; i++) {
		buttons[i].handleEvent(e);
	}
}