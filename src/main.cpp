#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

int main(int, char**) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window{ SDL_CreateWindow(
		"Hello Window!", 800, 600, 0
	) };

	bool isRunning = true;
	SDL_Event e;

	while (isRunning) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}