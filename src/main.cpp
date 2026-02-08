#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Window.h"

int main(int, char**) {
	SDL_Init(SDL_INIT_VIDEO);

	Window window;

	bool isRunning = true;
	SDL_Event e;

	while (isRunning) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}
	}

	SDL_Quit();

	return 0;
}