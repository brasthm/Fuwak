#include "UIDialog.h"
#include "UIText.h"
#include "UIButton.h"

#include "../UIModel.h"
#include "../../main.h"

#include <iostream>


UIDialog::UIDialog(UIModel* model, const std::string& name, float x, float y, float w, float h) : UIContainer(model, x, y, w, h)
{
	titlePanel_ = new UIPanel(model_, x, y, w, 50, sf::Color(66, 67, 71, 200), 1, sf::Color(104, 104, 108, 200));
	add(titlePanel_);
	add(new UIPanel(model_, x, y + 55, w, h - 55, sf::Color(66, 67, 71, 200), 1, sf::Color(104, 104, 108, 200)));

	add(new UIText(model_, name, sf::Text::Regular, 30, x + 5, y + 5, w - 10, 50));

	UIVerticalStacker* core = new UIVerticalStacker(model_, x + 5, y + 60, w - 10, h - 60);
	core_ = new UIVerticalStacker(model_, x + 5, y + 60, w - 10, h - 55 - 50);
	buttons_ = new UIHorizontalStacker(model_, x + 5, y + h - 50, w - 10, 30);

	core->add(core_);
	core->add(buttons_);

	add(core);

	dragged_ = false;
}

void UIDialog::addCore(UIComponant* comp)
{
	core_->add(comp);
}

void UIDialog::addButtons(const std::string& text, EventResponse* rep)
{
	if(rep != nullptr) rep->setCaller(this);
	buttons_->add(new UIButton(model_, text, 0, 0, 100, 30, sf::Color(112, 112, 112), sf::Color(156, 156, 156), rep));
}

void UIDialog::recieve(MouseLeftDragEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), DEFAULT_VIEW);
	sf::Vector2f startingPos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->startingX(), ev->startingY()), DEFAULT_VIEW);

	if (dragged_) {
		move(pos.x - clicPosX_, pos.y - clicPosY_);
		ev->accept();
	}
	else if (titlePanel_->contains(startingPos.x, startingPos.y)){
		*rep = new EventResponseSetFocus(model_);
		(*rep)->setCaller(this);
		dragged_ = true;
		clicPosX_ = startingPos.x - x_;
		clicPosY_ = startingPos.y - y_;
		ev->accept();
	}
	else {
		UIContainer::recieve(ev, rep);
	}

	
}

void UIDialog::recieve(MouseLeftClickEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), DEFAULT_VIEW);
	if (contains(pos.x, pos.y)) {
		*rep = new EventResponseSetFocus(model_);
		(*rep)->setCaller(this);

		UIContainer::recieve(ev, rep);

		ev->accept();
	}
	
}

void UIDialog::recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep)
{
	dragged_ = false;

	UIContainer::recieve(ev, rep);

	//ev->accept();
}

void UIDialog::add(UIComponant* comp)
{
	UIContainer::add(comp);
}
