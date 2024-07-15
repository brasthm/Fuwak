#include "ScreenTestB.h"

#include "ScreenManager.h"
#include "ScreenTestC.h"

ScreenTestB::ScreenTestB(ScreenManager* manager) : Screen(manager)
{
}

void ScreenTestB::display(sf::RenderWindow& window)
{
	sf::RectangleShape rect(sf::Vector2f(200.f, 200.f));;

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.scancode == sf::Keyboard::Scan::Escape)
				manager_->back();
			if (event.key.scancode == sf::Keyboard::Scan::Q)
				manager_->addStack(new ScreenTestC(manager_));
			if (event.key.scancode == sf::Keyboard::Scan::W)
				manager_->skipStack(new ScreenTestC(manager_));
		}
	}

	window.clear();
	window.draw(rect);
	window.display();
}
