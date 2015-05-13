#include "Widget.h"

Widget::Widget() {
	pos.x = 0;
	pos.y = 0;
}

Widget::Widget(int x, int y) {
	pos.x = x;
	pos.y = y;
}

void Widget::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;
}