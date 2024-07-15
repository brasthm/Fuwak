#ifndef FUWAK_UI_CONTAINER_H
#define FUWAK_UI_CONTAINER_H

#include "UIComponant.h"

#include <vector>

class UIDisplayer;




class UIContainer : public UIComponant
{
public:
	UIContainer(UIModel *model, float x, float y, float w, float h) : UIComponant(model, x, y, w, h) {};
	virtual void add(UIComponant* comp);
	void move(float x, float y) override;
	void resize(float w, float h) override;
	void draw(UIDisplayer* displayer) override;

	virtual void recieve(KeyboardPressEvent* ev, EventResponse** rep);
	virtual void recieve(KeyboardHoldEvent* ev, EventResponse** rep);
	virtual void recieve(MouseMoveEvent* ev, EventResponse** rep);
	virtual void recieve(MouseHoverEvent* ev, EventResponse** rep);
	virtual void recieve(MouseRightClickEvent* ev, EventResponse** rep);
	virtual void recieve(MouseLeftClickEvent* ev, EventResponse** rep);
	virtual void recieve(MouseRightDragEvent* ev, EventResponse** rep);
	virtual void recieve(MouseLeftDragEvent* ev, EventResponse** rep);
	virtual void recieve(MouseRightDragReleaseEvent* ev, EventResponse** rep);
	virtual void recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep);
	virtual void recieve(MouseWheelScrollEvent* ev, EventResponse** rep);
	virtual void recieve(MouseMiddleClickEvent* ev, EventResponse** rep);
protected:
	std::vector<UIComponant*> content_;
};

#endif 

