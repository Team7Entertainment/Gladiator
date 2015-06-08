#include "Region.h"

Region::Region() {
	active = false;
}

void Region::scroll(int x, int y) {
	for (auto &&p : blocks)
		p->scroll(x, y);
}

bool Region::isActive() {
	return active;
}

void Region::Activate() {
	active = true;
}

void Region::Deactivate() {
	active = false;
}