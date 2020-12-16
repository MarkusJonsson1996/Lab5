#include "point2d.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <vector>

void event_handler(SDL_Event* event, vector<Shape*>* shapes);
void renderer_update(SDL_Renderer* renderer);

bool running = true;

int main(int argc, char* args[]) {
	
	vector<Shape*> shapes;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("mywindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1360, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	while (running) {
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event)) if (event.type == SDL_KEYDOWN) event_handler(&event, &shapes);
		
		for (int i = 0; i < shapes.size(); i++) shapes[i]->render(renderer); 

		SDL_RenderPresent(renderer);
	}
	
	SDL_Quit();

	return 0;
}

void event_handler(SDL_Event* event, vector<Shape*>* shapes) {

	Point2d point((float)(rand() % 1360), (float)(rand() % 720));
	uint8_t col[4] = { rand() % 256, rand() % 256, rand() % 256, 255 };

	if (event->key.keysym.scancode == SDL_SCANCODE_Q)	running = false;

	else if (event->key.keysym.sym == SDLK_c) {
		shapes->push_back( new Circle (point, col, (float)(rand() % 200)) );

	}

	else if (event->key.keysym.sym == SDLK_t) {
		shapes->push_back( new Triangle(point, col, (float)(rand() % 400), (float)(rand() % 400)) );

	}

	else if (event->key.keysym.sym == SDLK_r) {
		shapes->push_back( new Rectangle(point, col, (float)(rand() % 400), (float)(rand() % 400)) );

	}

	else if (event->key.keysym.sym == SDLK_x) {
		for (int i = 0; i < shapes->size(); i++) {
			delete shapes->at(i);
		}
		while (!shapes->empty()) shapes->pop_back();
		shapes->shrink_to_fit();
	}

}
void renderer_update(SDL_Renderer* renderer) {
	
}