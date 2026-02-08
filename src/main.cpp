#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Window.h"
#include "UI.h"

int main(int, char**) {
	SDL_Init(SDL_INIT_VIDEO);

	Window window;
	UI UIManager;

	bool isRunning = true;
	SDL_Event e;

	while (isRunning) {
		while (SDL_PollEvent(&e)) {
			UIManager.handleEvent(e);
			if (e.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}

		window.render();
		UIManager.render(window.getSurface());
		window.update();
	}

	SDL_Quit();

	return 0;
}