#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Window.h"
#include "Rectangle.h"

int main(int, char**) {
	SDL_Init(SDL_INIT_VIDEO);

	Window window;
	Rectangle rect{ SDL_Rect{50, 50, 50, 50} };

	bool isRunning = true;
	SDL_Event e;

	while (isRunning) {
		while (SDL_PollEvent(&e)) {
			rect.handleEvent(e);
			if (e.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}

		window.render();
		rect.render(window.getSurface());
		window.update();
	}

	SDL_Quit();

	return 0;
}