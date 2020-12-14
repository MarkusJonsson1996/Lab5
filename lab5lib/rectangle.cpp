#include "rectangle.h"

Rectangle::Rectangle(Point2d pos, unsigned int* colorAlpha, float height, float witdh): Shape (pos, colorAlpha), width(witdh), height(height) {
}

void Rectangle::render(SDL_Renderer* renderer) {
	cout << "Rendering rectangle: " << endl;
	cout << "\tWidth: " << this->width << endl;
	cout << "\tHeight: " << this->height << endl;
	cout << "\tPosition " << this->get_string_pos() << endl;

	SDL_RenderDrawLine(renderer,
		(int)this->get_pos().get_x(),
		(int)this->get_pos().get_y(),
		(int)this->get_pos().get_x() + (int)this->width,
		(int)this->get_pos().get_y()
	);
	SDL_RenderDrawLine(renderer,
		(int)this->get_pos().get_x(),
		(int)this->get_pos().get_y(),
		(int)this->get_pos().get_x(),
		(int)this->get_pos().get_y() - (int)this->height
	);
	SDL_RenderDrawLine(renderer,
		(int)this->get_pos().get_x() + (int)this->width,
		(int)this->get_pos().get_y(),
		(int)this->get_pos().get_x() + (int)this->width,
		(int)this->get_pos().get_y() - (int)this->height
	);
	SDL_RenderDrawLine(renderer,
		(int)this->get_pos().get_x(),
		(int)this->get_pos().get_y() - (int)this->height,
		(int)this->get_pos().get_x() + (int)this->width,
		(int)this->get_pos().get_y() - (int)this->height
	);

}