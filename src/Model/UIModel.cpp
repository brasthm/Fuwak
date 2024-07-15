#include "UIModel.h"

#include "../Displayer/UIDisplayer.h"

#include <iostream>

UIModel::UIModel(EventDispatcher* ed) : EventReciever(ed), componants_(0)
{
}

UIModel::~UIModel()
{
	
}

void UIModel::add(UIComponant* comp)
{
	componants_->push_back(comp);
}

void UIModel::add(UIContainer* comp)
{
	componants_->push_back(comp);
}

void UIModel::render(UIDisplayer *uiDisplayer)
{
	uiDisplayer->clear();
	for (int i = 0; i < componants_->size(); i++) {
		uiDisplayer->newGroup();
		componants_->at(i)->draw(uiDisplayer);
	}
}

void UIModel::focus(UIComponant* comp)
{
	auto it = std::find(componants_->begin(), componants_->end(), comp);
	std::rotate(it, it + 1, componants_->end());
}

void UIModel::remove(UIComponant* comp)
{
	auto it = std::find(componants_->begin(), componants_->end(), comp);
	if (it != componants_->end()) {
		delete* it;
		componants_->erase(it);
	}
}

void UIModel::setState(UIState* state)
{
	componants_ = state->componants;
}

void UIModel::recieve(KeyboardPressEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(KeyboardHoldEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseMoveEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseHoverEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseRightClickEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseLeftClickEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseRightDragEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseLeftDragEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseRightDragReleaseEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseWheelScrollEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}

void UIModel::recieve(MouseMiddleClickEvent* ev, EventResponse** rep)
{
	for (int i = componants_->size() - 1; i >= 0; i--) {
		if (ev->processed()) break;
		componants_->at(i)->recieve(ev, rep);
	}
}



