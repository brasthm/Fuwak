#include "UIPanel.h"

#include "../../Displayer/UIDisplayer.h"

UIPanel::UIPanel(UIModel* model, float x, float y, float w, float h, sf::Color backgroundColor, int outlineThickness, sf::Color outlineColor) :
	UIContainer(model, x, y, w, h), backgroundColor_(backgroundColor), 
	outlineThickness_(outlineThickness), outlineColor_(outlineColor)
{
}

void UIPanel::draw(UIDisplayer* displayer)
{
	displayer->drawComponant(this);
}

int UIPanel::getOutlineThickness()
{
	return outlineThickness_;
}

sf::Color UIPanel::getBackgroundColor()
{
	return backgroundColor_;
}

sf::Color UIPanel::getOutlineColor()
{
	return outlineColor_;
}
