#ifndef FUWAK_EVENTEMITTER_H
#define FUWAK_EVENTEMITTER_H

#include "EventHandler.h"

class SFMLEventHandler : public EventHandler
{
public:

	SFMLEventHandler();

	bool pollEvent(sf::RenderWindow& window);

private:

	sf::Clock stillMouseTimer_;
	sf::Vector2f lastRightMouseButtonClickPosition_, lastLeftMouseButtonClickPosition_, lastMousePosition_;
	bool mouseMoved_, draggingLeft_, draggingRight_, keyPressed_;

};

#endif