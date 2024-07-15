#include "UIComponant.h"

#include "../../Displayer/UIDisplayer.h"

bool UIComponant::contains(float x, float y)
{
	return sf::FloatRect(x_, y_, w_, h_).contains(x, y);
}

void UIComponant::move(float x, float y)
{
	x_ = x;
	y_ = y;
}

void UIComponant::resize(float w, float h)
{
	if (w >= 0) w_ = w;
	if (h >= 0) h_ = h;
}

void UIComponant::draw(UIDisplayer* displayer)
{
	displayer->drawComponant(this);
}

sf::FloatRect UIComponant::getCoords()
{
	return sf::FloatRect(x_, y_, w_, h_);
}

