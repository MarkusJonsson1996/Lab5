#pragma once
#include <iostream>
#include "point2d.h"
#include "SDL.h"

using namespace std;

class Shape {
public:
	Shape(Point2d pos, unsigned int* colorAlpha);
	
	string get_string_pos();
	Point2d get_pos();

	virtual void render(SDL_Renderer* renderer);

private:
	Point2d pos;
	unsigned int colorAlpha[4];
};