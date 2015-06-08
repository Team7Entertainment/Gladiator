#include "Vendor.h"
#ifndef REG
#include "Region.h"
#define REG
#endif

class LudusMagnus: public Region{
	public:
		LudusMagnus();
		LudusMagnus(SDL_Renderer* renderer);
		void update(SDL_Event* e);

	private:
		Texture* sheet = new Texture();
};