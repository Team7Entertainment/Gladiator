#include "Enemy.h"
#ifndef REG
#include "Region.h"
#define REG
#endif

class Arena: public Region {
	public:
		Arena();
		void update(SDL_Event* e);

	private:


};