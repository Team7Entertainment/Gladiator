#ifndef ARTIFICIAL
#include "AI.h"
#define ARTIFICIAL
#endif
#ifndef PLAT
#include "Platform.h"
#define PLAT
#endif
#include <vector>

class Region {
	public:
		Region();
		virtual void update(SDL_Event* e) = 0;
		void scroll(int x, int y);
		bool isActive();
		void Activate();
		void Deactivate();

	protected:
		std::vector<AI*> ais;
		std::vector<Platform*> blocks;
		bool active;
};