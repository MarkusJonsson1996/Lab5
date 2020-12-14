#pragma once
#include "shape.h"
class Circle : public Shape {
public:

	Circle(Point2d, unsigned int*, float);

	void render(SDL_Renderer* renderer);
private:
	float rad;
};

