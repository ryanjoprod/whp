#pragma once

#include <SDL3/SDL.h>

#include <iostream>

#include "Rectangle.h"

class UI;

class Button : public Rectangle {
public:
	Button(
		UI& UIManager,
		const SDL_Rect& rect,
		Rectangle& target
	)
	: Rectangle{ rect },
	  UIManager{ UIManager },
	  target{target}
	{
		setColor({ 255, 165, 0, 255 });
	}

	// void render(SDL_Surface* surface) {}

	// void handleEvent(SDL_Event& e) {}

	/*
	void onMouseEnter() override {
		std::cout << "Hello mouse!\n";
	}

	void onMouseExit() override {
		std::cout << "Goodbye mouse!\n";
	}
	*/

	void onLeftClick() override;

private:
	Rectangle& target;
	UI& UIManager;
};