#include "Vendor.h"
#ifndef REG
#include "Region.h"
#define REG
#endif

class LudusMagnus: public Region{
	public:
		LudusMagnus();
		void update(SDL_Event* e);

	private:

};