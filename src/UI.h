#pragma once

#include <SDL3/SDL.h>

#include <vector>
#include <memory>

#include "Rectangle.h"
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
	
	void render(SDL_Surface * surface) const {
		/*
		for (auto& rect : rectangles) {
			rect->render(surface);
		}
		*/
		a.render(surface);
		b.render(surface);
		c.render(surface);
	}

	void handleEvent(SDL_Event& e) {
		/*
		for (auto& rect : rectangles) {
			rect->handleEvent(e);
		}
		*/
		a.handleEvent(e);
		b.handleEvent(e);
		c.handleEvent(e);
	}

	void setRectangleColors(const SDL_Color& color) {
		a.setColor(color);
		b.setColor(color);
	}

private:
	// std::vector<std::unique_ptr<Rectangle>> rectangles;
	Rectangle a{ SDL_Rect{50, 50, 50, 50} };
	Rectangle b{ SDL_Rect{150, 50, 50, 50} };
	Button c{*this, SDL_Rect{250, 50, 50, 50}, a };
};