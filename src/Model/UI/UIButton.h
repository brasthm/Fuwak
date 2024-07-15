#ifndef FUWAK_UI_BUTTON_H
#define FUWAK_UI_BUTTON_H

#include "UIContainer.h"

#include "SFML/Graphics.hpp"

class UIButton : public UIContainer
{
public:
	UIButton(UIModel* model, const std::string &text, float x, float y, float w, float h, sf::Color backgroundColor, sf::Color hoverColor, EventResponse *onClick=nullptr);
	~UIButton();
	void draw(UIDisplayer* displayer) override;
	sf::Color getDisplayColor();
	void addOnClick(EventResponse* onClick);

	void recieve(MouseMoveEvent* ev, EventResponse** rep) override;
	void recieve(MouseLeftClickEvent* ev, EventResponse** rep) override;
	void recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep) override;
private:
	sf::Color backgroundColor_, hoverColor_;
	std::string text_;
	bool hover_;
	EventResponse* onClick_;
	
};

#endif
