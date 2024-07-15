#include "EventReciever.h"

void KeyboardPressEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void KeyboardHoldEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseMoveEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseHoverEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseRightClickEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseLeftClickEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseRightDragEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseLeftDragEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseRightDragReleaseEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseLeftDragReleaseEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseMiddleClickEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}

void MouseWheelScrollEvent::process(EventReciever* r, EventResponse** rep)
{
	r->recieve(this, rep);
}
