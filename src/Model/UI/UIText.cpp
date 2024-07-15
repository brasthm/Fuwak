#include "UIText.h"

#include "../../Displayer/UIDisplayer.h"

UIText::UIText(UIModel* model, const std::string& text, sf::Text::Style style, int size, float x, float y, float w, float h, sf::Color textColor, int oulineThickness, sf::Color outlineColor) :
	UIComponant(model, x, y, w, h), text_(text), style_(style), textColor_(textColor), size_(size), 
	outlineColor_(outlineColor), outlineThickness_(oulineThickness)
{
	
}

void UIText::draw(UIDisplayer* displayer)
{
	displayer->drawComponant(this);
}

sf::Color UIText::getTextColor()
{
	return textColor_;
}

sf::Color UIText::getOutlineColor()
{
	return outlineColor_;
}

sf::Text::Style UIText::getStyle()
{
	return style_;
}

int UIText::getSize()
{
	return size_;
}

int UIText::getOutlineThickness()
{
	return outlineThickness_;
}

std::string &UIText::getText()
{
	return text_;
}
