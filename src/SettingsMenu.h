#pragma once

#include <SDL3/SDL.h>

#include <iostream>

#include "UserEvents.h"
#include "Button.h"

class SettingsMenu {
public:
	void render(SDL_Surface* surface) const {
		if (!isOpen) return;

		const auto* fmt = SDL_GetPixelFormatDetails(surface->format);

		SDL_FillSurfaceRect(
			surface,
			&rect,
			SDL_MapRGB(
				fmt, nullptr,
				color.r, color.g, color.b
			)
		);
	}

	void handleEvent(SDL_Event& e) {
		if (e.type == UserEvents::OPEN_SETTINGS ||
			e.type == UserEvents::CLOSE_SETTINGS) {
			handleUserEvent(e.user);
		}
		if (e.type == UserEvents::OPEN_SETTINGS) {
			isOpen = true;
		}

		// If the settings menu isn't open, we ignore
		// all other events
		if (!isOpen) return;

		if (e.type == UserEvents::CLOSE_SETTINGS) {
			isOpen = false;
		}
	}

private:
	bool isOpen{ false };
	SDL_Rect rect{ 100, 50, 200, 200 };
	SDL_Color color{ 150, 150, 150, 255 };

	void handleUserEvent(SDL_UserEvent& e) {
		if (e.type == UserEvents::OPEN_SETTINGS) {
			isOpen = true;

			auto* instigator{ static_cast<Button*>(e.data1) };

			std::cout << "I was opened from a button in " << instigator->getLocation() << "\n";

			rect.x = instigator->getConfig().x;
			rect.y = instigator->getConfig().y;
			if (instigator->getConfig().page == UserEvents::SettingsPage::GAMEPLAY) {
				std::cout << "Page: Gameplay Settings\n";
			}
		}
		else if (e.type == UserEvents::CLOSE_SETTINGS) {
			isOpen = false;
		}
	}
};