#ifndef TEX
#define TEX
#include "Texture.h"
#endif

const int BUTTON_NUM = 4;

class MainMenu {
	public:
		MainMenu();
		void update();
		void handleMouse();

	private:
		Texture sheet;
};

MainMenu::MainMenu() {
	sheet.loadFromFile("menuSheet.png");
}