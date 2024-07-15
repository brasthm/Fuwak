#ifndef FUWAK_EVENT_RECIEVER_H
#define FUWAK_EVENT_RECIEVER_H

#include "Event.h"

class EventDispatcher;
class EventReciever;
class EventResponse;

class KeyboardPressEvent : public KeyboardEvent {
public:
	using KeyboardEvent::KeyboardEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};

class KeyboardHoldEvent : public KeyboardEvent {
public:
	using KeyboardEvent::KeyboardEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};

class MouseMoveEvent : public MouseEvent {
public:
	using MouseEvent::MouseEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};
class MouseHoverEvent : public MouseEvent {
public:
	using MouseEvent::MouseEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};
class MouseRightClickEvent : public MouseEvent {
public:
	using MouseEvent::MouseEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};
class MouseLeftClickEvent : public MouseEvent {
public:
	using MouseEvent::MouseEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};
class MouseRightDragEvent : public MouseDragEvent {
public:
	using MouseDragEvent::MouseDragEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};
class MouseLeftDragEvent : public MouseDragEvent {
public:
	using MouseDragEvent::MouseDragEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};
class MouseRightDragReleaseEvent : public MouseDragEvent {
public:
	using MouseDragEvent::MouseDragEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};
class MouseLeftDragReleaseEvent : public MouseDragEvent {
public:
	using MouseDragEvent::MouseDragEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};

class MouseWheelScrollEvent : public MouseEvent {
public:
	MouseWheelScrollEvent(sf::RenderWindow* window, float x, float y, float delta) :
		MouseEvent(window, x, y), delta_(delta) {};
	void process(EventReciever* r, EventResponse** rep) override;
	float delta() { return delta_; };
private:
	float delta_;
};

class MouseMiddleClickEvent : public MouseEvent {
public:
	using MouseEvent::MouseEvent;
	void process(EventReciever* r, EventResponse** rep) override;
};


class EventReciever {
public:
	EventReciever(EventDispatcher* dispatcher) : dispatcher_(dispatcher) {};

	virtual void recieve(Event* ev, EventResponse** rep) { 
		if(!ev->processed())
			ev->process(this, rep); 
	};

	virtual void recieve(KeyboardPressEvent* ev, EventResponse** rep) {};
	virtual void recieve(KeyboardHoldEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseMoveEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseHoverEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseRightClickEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseLeftClickEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseRightDragEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseLeftDragEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseRightDragReleaseEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseWheelScrollEvent* ev, EventResponse** rep) {};
	virtual void recieve(MouseMiddleClickEvent* ev, EventResponse** rep) {};

protected:
	EventDispatcher* dispatcher_;
};

#endif // !FUWAK_EVENT_RECIEVER_H