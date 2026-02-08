#pragma once

#include <SDL3/SDL.h>

// #include <vector>
// #include <memory>

#include "SettingsMenu.h"
#include "Button.h"

class UI {
public:
	/*
	UI() {
		int rowCount{ 5 }, colCount{ 12 };
		rectangles.reserve(rowCount * colCount);
		for (int row{ 0 }; row < rowCount; ++row) {
			for (int col{ 0 }; col < colCount; ++col) {
				rectangles.emplace_back(std::make_unique<Rectangle>(SDL_Rect{
					60 * col, 60 * row, 50, 50
				}));
			}
		}
	}
	*/
	
	void render(SDL_Surface* surface) const {
		/*
		for (auto& rect : rectangles) {
			rect->render(surface);
		}
		*/
		settingsButton.render(surface);
		settings.render(surface);
	}

	void handleEvent(SDL_Event& e) {
		/*
		for (auto& rect : rectangles) {
			rect->handleEvent(e);
		}
		*/
		settingsButton.handleEvent(e);
		settings.handleEvent(e);
	}

private:
	// std::vector<std::unique_ptr<Rectangle>> rectangles;
	Button settingsButton{ {50, 50, 50, 50} };
	SettingsMenu settings;
};