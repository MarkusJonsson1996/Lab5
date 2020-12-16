#include "shape.h"

Shape::Shape() { 

}
Shape::Shape(Point2d pos, uint8_t* colorAlpha) : pos(pos) {
	for (int i = 0; i < 4; i++) {

		if (colorAlpha[i] < 0) colorAlpha[i] += 255;
		else if (colorAlpha[i] > 255) colorAlpha -= 255;

		this->colorAlpha[i] = colorAlpha[i];
	}
}

string Shape::get_string_pos() {
	return pos.to_string();
}
Point2d Shape::get_pos() {
	return pos;
}
uint8_t Shape::get_color_alpha(uint8_t i){	
	Uint8 ret = -1;

	if (i < 5 || i > -1) ret = this->colorAlpha[i];

	return ret;
}

void Shape::render(SDL_Renderer* renderer) {
	cout << "Rendering shape" << endl;
}