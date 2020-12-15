#pragma once
#include "shape.h"

class Triangle : public Shape {
public:

	Triangle(Point2d pos, unsigned int* colorAlpha, float base, float height);

	void render(SDL_Renderer* renderer);
private:
	float base, height;
};
