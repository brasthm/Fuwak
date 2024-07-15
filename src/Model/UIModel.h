#ifndef FUWAK_UI_MODEL_H
#define FUWAK_UI_MODEL_H

#include "../EventHandler/EventReciever.h"
#include "../EventHandler/EventHandler.h"

#include "UI/UIComponant.h"
#include "UI/UIContainer.h"

#include <vector>
#include <SFML/Graphics.hpp>

class UIState {
public:
	UIState() { componants = new std::vector<UIComponant*>(); };
	~UIState() { 
		for (auto c : *componants) {
			delete c;
		}
		delete componants; 
	};
	std::vector<UIComponant*> *componants;
};


class UIModel : public EventReciever
{
public:
	UIModel(EventDispatcher* ed);
	~UIModel();
	void add(UIComponant* comp);
	void add(UIContainer* comp);
	void render(UIDisplayer* uiDisplayer);
	void focus(UIComponant* comp);
	void remove(UIComponant* comp);

	void setState(UIState* state);

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
	std::vector <UIComponant*> *componants_;
};

class EventResponseSetFocus : public EventResponse {
public:
	EventResponseSetFocus(UIModel* model) :
		model_(model){};
	void execute() {
		model_->focus(static_cast<UIComponant*>(caller_));
	};
private:
	UIModel* model_;
};

class EventResponseCloseDialog : public EventResponse {
public:
	EventResponseCloseDialog(UIModel* model) : model_(model){};
	void execute() {
		model_->remove(static_cast<UIComponant*>(caller_));
	};
private:
	UIModel* model_;
};

#endif