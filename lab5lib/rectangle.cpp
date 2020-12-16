#include "rectangle.h"

Rectangle::Rectangle(Point2d pos, uint8_t* colorAlpha, float height, float witdh): Shape (pos, colorAlpha), width(witdh), height(height) {
}

void Rectangle::render(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer, 
		this->get_color_alpha(0), 
		this->get_color_alpha(1), 
		this->get_color_alpha(2),
		this->get_color_alpha(3)
	);

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