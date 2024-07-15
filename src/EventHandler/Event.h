#ifndef FUWAK_EVENT_H
#define FUWAK_EVENT_H

#include <SFML/Graphics.hpp>

enum EventType {
	Mouse,
	Keyboard,
	Controller,
	Network
};

class EventReciever;
class EventResponse;


class Event
{
public:
	Event(EventType type) : processed_(false), type_(type)  {};
	void accept() { processed_ = true; };
	bool processed() { return processed_; };
	virtual void process (EventReciever* r, EventResponse** rep) = 0;
	
protected:
	
private:
	bool processed_;
	EventType type_;
};

class KeyboardEvent : public Event {
public:
	KeyboardEvent(sf::Keyboard::Scancode scancode, bool alt, bool ctrl, bool maj) :
		Event(EventType::Keyboard), scancode_(scancode), alt_(alt), ctrl_(ctrl), maj_(maj) {};

	sf::Keyboard::Scancode scancode() { return scancode_; };
	bool alt() { return alt_; };
	bool maj() { return maj_; };
	bool ctrl() { return ctrl_; };

protected:
	sf::Keyboard::Scancode scancode_;
	bool alt_, ctrl_, maj_;
};

class MouseEvent : public Event {
public:
	MouseEvent(sf::RenderWindow* window, int x, int y) :
		Event(EventType::Mouse), window_(window), x_(x), y_(y) {};

	int x() { return x_; }
	int y() { return y_; }
	sf::RenderWindow* window() { return window_; }

protected:
	int x_, y_;
	sf::RenderWindow* window_;
};

class MouseDragEvent : public MouseEvent {
public:
	MouseDragEvent(sf::RenderWindow* window, int startingX, int startingY, int x, int y) :
		MouseEvent(window, x, y), startingX_(startingX), startingY_(startingY) {};

	int startingX() { return startingX_; };
	int startingY() { return startingY_; };

protected:
	int startingX_, startingY_;
};


#endif // !FUWAK_EVENT_H