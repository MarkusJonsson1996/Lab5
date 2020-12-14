#include "shape.h"

Shape::Shape(Point2d pos, unsigned int* colorAlpha) : pos(pos) {
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
void Shape::render(SDL_Renderer* renderer) {
	cout << "Rendering shape" << endl;
}