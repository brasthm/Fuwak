#include "UIContainer.h"

void UIContainer::add(UIComponant* comp)
{
	content_.push_back(comp);
}

void UIContainer::move(float x, float y)
{
	for (auto c : content_) {
		sf::FloatRect box = c->getCoords();
		float newX = box.left - x_ + x, newY = box.top - y_ + y;
		c->move(newX, newY);
	}

	UIComponant::move(x, y);
}

void UIContainer::resize(float w, float h)
{
	for (auto c : content_) {
		c->resize(w, h);
	}
	UIComponant::resize(w, h);
}

void UIContainer::draw(UIDisplayer* displayer)
{
	for (auto c : content_) {
		c->draw(displayer);
	}
}

void UIContainer::recieve(KeyboardPressEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(KeyboardHoldEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseMoveEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseHoverEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseRightClickEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseLeftClickEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseRightDragEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseLeftDragEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseRightDragReleaseEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseWheelScrollEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

void UIContainer::recieve(MouseMiddleClickEvent* ev, EventResponse** rep)
{
	for (auto c : content_) {
		c->recieve(ev, rep);
	}
}

