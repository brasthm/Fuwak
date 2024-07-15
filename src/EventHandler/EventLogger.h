#pragma once
#include "EventReciever.h"



class EventLogger :
	public EventReciever
{
public:
	EventLogger(EventDispatcher* d) : EventReciever(d) {
		logKeyboardEvent_ = false;
		logMouseMouvementEvent_ = false;
		logMouseButtonEvent_ = false;
	};

	void logKeyboardEvent() { logKeyboardEvent_ = true; };
	void logMouseMouvementEvent() { logMouseMouvementEvent_ = true; };
	void logMouseButtonEvent() { logMouseButtonEvent_ = true; };

	void recieve(KeyboardPressEvent* ev, EventResponse** rep) override;
	void recieve(KeyboardHoldEvent* ev, EventResponse** rep) override;
	void recieve(MouseMoveEvent* ev, EventResponse** rep) override;
	void recieve(MouseHoverEvent* ev, EventResponse** rep) override;
	void recieve(MouseRightClickEvent* ev, EventResponse** rep) override;
	void recieve(MouseLeftClickEvent* ev, EventResponse** rep) override;
	void recieve(MouseRightDragEvent* ev, EventResponse** rep) override;
	void recieve(MouseLeftDragEvent* ev, EventResponse** rep) override;
	void recieve(MouseRightDragReleaseEvent* ev, EventResponse** rep) override;
	void recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep) override;
	void recieve(MouseWheelScrollEvent* ev, EventResponse** rep) override;
	void recieve(MouseMiddleClickEvent* ev, EventResponse** rep) override;

private:
	bool logKeyboardEvent_, logMouseMouvementEvent_, logMouseButtonEvent_;
};

