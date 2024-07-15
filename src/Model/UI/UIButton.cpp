#include "UIButton.h"

#include "../../Displayer/UIDisplayer.h"
#include "../../EventHandler/EventHandler.h"
#include "UIText.h"

#include <iostream>

UIButton::UIButton(UIModel* model, const std::string& text, float x, float y, float w, float h, sf::Color backgroundColor, sf::Color hoverColor, EventResponse* onClick) :
	UIContainer(model, x, y, w, h), text_(text), 
	backgroundColor_(backgroundColor), hoverColor_(hoverColor), hover_(false),
	onClick_(onClick)
{
	content_.emplace_back(new UIText(model_, text, sf::Text::Style::Regular, static_cast<int>(0.7*h_), x_, y_, w_, h_));

	if(onClick_ != nullptr)
		onClick_->setDeletable(false);
}

UIButton::~UIButton()
{
	delete onClick_;
}

void UIButton::draw(UIDisplayer* displayer)
{
	displayer->drawComponant(this);

	UIContainer::draw(displayer);
}

sf::Color UIButton::getDisplayColor()
{
	return hover_ ? hoverColor_ : backgroundColor_;
}

void UIButton::addOnClick(EventResponse* onClick)
{
	onClick_ = onClick;

	if(onClick_!= nullptr)
		onClick_->setDeletable(false);
}

void UIButton::recieve(MouseMoveEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), DEFAULT_VIEW);
	hover_ = contains(pos.x, pos.y);
}

void UIButton::recieve(MouseLeftClickEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), DEFAULT_VIEW);
	if(contains(pos.x, pos.y))
		*rep = onClick_;
}

void UIButton::recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), DEFAULT_VIEW);
	sf::Vector2f startingPos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->startingX(), ev->startingY()), DEFAULT_VIEW);
	if(contains(pos.x, pos.y) && contains(startingPos.x, startingPos.y))
		*rep = onClick_;
}
