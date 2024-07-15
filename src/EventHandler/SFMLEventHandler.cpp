#include "SFMLEventHandler.h"
#include "EventDispatcher.h"
#include "../System/Utils.h"

#include <iostream>

constexpr float TIME_TO_ENTER_HOVER = 2.f;
constexpr float DISTANCE_TO_ENTER_DRAG = 10.f;
constexpr float MINIMUM_MOUVEMENT_DISTANCE = 1.f;



SFMLEventHandler::SFMLEventHandler() : draggingLeft_(false), draggingRight_(false), keyPressed_(false), mouseMoved_(false)
{

}

bool SFMLEventHandler::pollEvent(sf::RenderWindow& window)
{
	std::vector<Event*> events;
	sf::Event ev;



	bool mouvementDetected = false;

	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			return true;

		//mouseMovePos = window.mapPixelToCoords(sf::Vector2i(ev.mouseMove.x, ev.mouseMove.y));
		//mouseButtonPos = window.mapPixelToCoords(sf::Vector2i(ev.mouseButton.x, ev.mouseButton.y));
		//mouseWheelPos = window.mapPixelToCoords(sf::Vector2i(ev.mouseWheelScroll.x, ev.mouseWheelScroll.y));

		// Mouse

		// Mouse Mouvement
		if (ev.type == sf::Event::MouseMoved) {
			mouvementDetected = false;
			if (Utils::distance(lastMousePosition_, sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y)) >= MINIMUM_MOUVEMENT_DISTANCE) {
				mouvementDetected = true;
			}
			lastMousePosition_.x = ev.mouseMove.x;
			lastMousePosition_.y = ev.mouseMove.y;
		}

		

		// Mouse Button Pressed
		if (ev.type == sf::Event::MouseButtonPressed) {
			if (ev.mouseButton.button == sf::Mouse::Button::Left) {
				lastLeftMouseButtonClickPosition_.x = ev.mouseButton.x;
				lastLeftMouseButtonClickPosition_.y = ev.mouseButton.y;
				draggingLeft_ = false;
			}
			if (ev.mouseButton.button == sf::Mouse::Button::Right) {
				lastRightMouseButtonClickPosition_.x = ev.mouseButton.x;
				lastRightMouseButtonClickPosition_.y = ev.mouseButton.y;
				draggingRight_ = false;
			}
		}

		// Mouse Button Released

		if (ev.type == sf::Event::MouseButtonReleased) {
			if (ev.mouseButton.button == sf::Mouse::Button::Left) {
				Event* newEvent;

				if (draggingLeft_)
					newEvent = new MouseLeftDragReleaseEvent(&window, lastLeftMouseButtonClickPosition_.x, lastLeftMouseButtonClickPosition_.y,
						ev.mouseButton.x, ev.mouseButton.y);
				else
					newEvent = new MouseLeftClickEvent(&window, ev.mouseButton.x, ev.mouseButton.y);

				events.push_back(newEvent);
			}
			if (ev.mouseButton.button == sf::Mouse::Button::Right) {
				Event* newEvent;

				if (draggingRight_)
					newEvent = new MouseRightDragReleaseEvent(&window, lastLeftMouseButtonClickPosition_.x, lastLeftMouseButtonClickPosition_.y,
						ev.mouseButton.x, ev.mouseButton.y);
				else
					newEvent = new MouseRightClickEvent(&window, ev.mouseButton.x, ev.mouseButton.y);

				events.push_back(newEvent);
			}
			if (ev.mouseButton.button == sf::Mouse::Button::Middle) {
				events.push_back(new MouseMiddleClickEvent(&window, ev.mouseButton.x, ev.mouseButton.y));
			}
		}

		//MouseWheel
		if (ev.type == sf::Event::MouseWheelScrolled) {
			events.push_back(new MouseWheelScrollEvent(&window, ev.mouseWheelScroll.x, ev.mouseWheelScroll.y, ev.mouseWheelScroll.delta));
		}

		//Keyboard
		if (ev.type == sf::Event::KeyPressed) {
			Event* newEvent;

			if (keyPressed_)
				newEvent = new KeyboardHoldEvent(ev.key.scancode, ev.key.alt, ev.key.control, ev.key.shift);
			else
				newEvent = new KeyboardPressEvent(ev.key.scancode, ev.key.alt, ev.key.control, ev.key.shift);

			events.push_back(newEvent);

			keyPressed_ = true;
		}

		if (ev.type == sf::Event::KeyReleased) {
			keyPressed_ = false;
		}
	}

	// If no mouse mouvement was polled, the mouse was staying still
	if (mouvementDetected) {
		Event* newEvent;

		// Checking for drag and drop
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (draggingLeft_ ||
			Utils::distance(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y), lastLeftMouseButtonClickPosition_) > DISTANCE_TO_ENTER_DRAG)) {
			newEvent = new MouseLeftDragEvent(&window, lastLeftMouseButtonClickPosition_.x, lastLeftMouseButtonClickPosition_.y,
				ev.mouseMove.x, ev.mouseMove.y);
			draggingLeft_ = true;
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && (draggingRight_ ||
			Utils::distance(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y), lastRightMouseButtonClickPosition_) > DISTANCE_TO_ENTER_DRAG)) {
			newEvent = new MouseRightDragEvent(&window, lastLeftMouseButtonClickPosition_.x, lastLeftMouseButtonClickPosition_.y,
				ev.mouseMove.x, ev.mouseMove.y);
			draggingRight_ = true;
		}
		else
			newEvent = new MouseMoveEvent(&window, ev.mouseMove.x, ev.mouseMove.y);


		events.push_back(newEvent);
		mouseMoved_ = true;

		lastMousePosition_.x = ev.mouseMove.x;
		lastMousePosition_.y = ev.mouseMove.x;
	}
	else {
		if (mouseMoved_) {
			stillMouseTimer_.restart();
		}
		mouseMoved_ = false;

		// Hover event if the mouse was still long enough
		if (stillMouseTimer_.getElapsedTime().asSeconds() >= TIME_TO_ENTER_HOVER) {
			Event* newEvent = new MouseHoverEvent(&window, ev.mouseMove.x, ev.mouseMove.y);
			events.push_back(newEvent);
		}
	}

	// Passing events to the next handler
	for (auto e : events) {
		handle(e);
	}


	for (auto e : events)
		delete e;

	return false;
}