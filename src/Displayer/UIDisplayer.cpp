#include "UIDisplayer.h"

void UIDisplayer::drawComponant(UIComponant* comp)
{
	comp->draw(this);
}

void UIDisplayer::drawComponant(UIButton* comp)
{
	sf::FloatRect rect = comp->getCoords();

	drawQuad(rect.left, rect.top, rect.width, rect.height, comp->getDisplayColor());
}

void UIDisplayer::drawComponant(UIText* comp)
{
	sf::FloatRect box = comp->getCoords();
	drawText(box.left, box.top, box.width, box.height, comp->getText(), comp->getSize(), comp->getStyle(),
		comp->getTextColor(), comp->getOutlineThickness(), comp->getOutlineColor());
}

void UIDisplayer::drawComponant(UIPanel* comp)
{
	sf::FloatRect box = comp->getCoords();
	drawQuad(box.left, box.top, box.width, box.height, comp->getBackgroundColor(), 
		comp->getOutlineThickness(), comp->getOutlineColor());
}
