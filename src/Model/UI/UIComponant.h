#ifndef FUWAK_UI_COMPONANT_H
#define FUWAK_UI_COMPONANT_H

#include <SFML/Graphics.hpp>

#include "../../EventHandler/EventReciever.h"


class UIDisplayer;
class UIModel;

class UIComponant
{
public:
	UIComponant(UIModel* model) : model_(model), x_(0), y_(0), w_(0), h_(0) {};
	UIComponant(UIModel* model, float x, float y, float w, float h) : model_(model), x_(x), y_(y), w_(w), h_(h) {};
	bool contains(float x, float y);
	virtual void move(float x, float y);
	virtual void resize(float w, float h);
	virtual void draw(UIDisplayer* displayer);
	sf::FloatRect getCoords();

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
	float x_, y_, w_, h_;
	UIModel* model_;
};

#endif