#ifndef ARTIFICIAL
#include "AI.h"
#define ARTIFICIAL
#endif

class Region {
	public:
		Region();
		virtual void update(SDL_Event* e);

	private:
		std::vector<AI> ais;

};