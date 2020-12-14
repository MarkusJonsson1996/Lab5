#include "point2d.h"
#include "rectangle.h"

int main(int argc, char* args[]) {
	Point2d pos1(150, 100);
	unsigned int col1[4] = { 134, 100, 45, 255 };

	Rectangle rec1(pos1, col1, 50, 100);


	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("mywindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	rec1.render(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

	return 0;
}