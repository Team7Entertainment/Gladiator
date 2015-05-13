#include "Button.h"
#include "Slider.h"
#include <vector>

class Menu {
	public:
		Menu(SDL_Renderer* renderer);
		Widget* getWidgetAtIndex(int index);
		void update(SDL_Event* e);
		int getClickedButton();
		void show();
		void hide();
		bool isShown();

	protected:
		bool shown = false;
		Texture* sheet = new Texture();
		std::vector<Widget*> widgets;
		virtual void initButtons() = 0;
};