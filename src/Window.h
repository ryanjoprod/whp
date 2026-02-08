#pragma once
#include <SDL3/SDL.h>

class Window {
public:
	Window() {
		window = SDL_CreateWindow(
			"Hello Window",
			800, 600,
			SDL_WINDOW_RESIZABLE
		);
	}

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	~Window() {
		if (window && SDL_WasInit(SDL_INIT_VIDEO)) {
			SDL_DestroyWindow(window);
		}
	}

private:
	SDL_Window* window{ nullptr };
};