#ifndef ARTIFICIAL
#include "AI.h"
#define ARTIFICIAL
#endif
#ifndef FIGHT
#include "Fighter.h"
#define FIGHT
#endif

class Enemy: public AI , public Fighter{
	public:
		Enemy();
		void update(SDL_Event* e);

	private:


};