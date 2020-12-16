#pragma once
#include "shape.h"
#include "SDL.h"

class Rectangle : public Shape {
public:
	Rectangle(Point2d pos, uint8_t* colorAlpha, float height, float width);

	void render(SDL_Renderer* renderer);
private:
	float width, height;
};

