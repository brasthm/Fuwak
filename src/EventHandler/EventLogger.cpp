#include "EventLogger.h"

#include <iostream>

void EventLogger::recieve(KeyboardPressEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logKeyboardEvent_) {
		key = "";
		key += ev->alt() ? "Alt+" : "";
		key += ev->ctrl() ? "Ctrl+" : "";
		key += ev->maj() ? "Maj+" : "";
		key += sf::Keyboard::getDescription(ev->scancode());
		std::cout << "EventHandlerDebugger: Keypressed recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(KeyboardHoldEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logKeyboardEvent_) {
		key = "";
		key += ev->alt() ? "Alt+" : "";
		key += ev->ctrl() ? "Ctrl+" : "";
		key += ev->maj() ? "Maj+" : "";
		key += sf::Keyboard::getDescription(ev->scancode());
		std::cout << "EventHandlerDebugger: KeyHold recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseMoveEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseMouvementEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse mouvement recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseHoverEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseMouvementEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse hover recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseRightClickEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseButtonEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse right button click recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseLeftClickEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseButtonEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse left button click recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseRightDragEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseMouvementEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse right button drag recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseLeftDragEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseMouvementEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse left button drag recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseRightDragReleaseEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseButtonEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse right button released recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseButtonEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse left button released recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseWheelScrollEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseButtonEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y()) + " / " + std::to_string((int)ev->delta());
		std::cout << "EventHandlerDebugger: Mouse wheel scroll recieved (" << key << ")" << std::endl;
	}
}

void EventLogger::recieve(MouseMiddleClickEvent* ev, EventResponse** rep)
{
	std::string key = "";

	if (logMouseButtonEvent_) {
		key = std::to_string((int)ev->x()) + " " + std::to_string((int)ev->y());
		std::cout << "EventHandlerDebugger: Mouse middle button click recieved (" << key << ")" << std::endl;
	}
}
