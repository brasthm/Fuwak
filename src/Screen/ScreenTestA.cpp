#include "ScreenManager.h"
#include "ScreenTestA.h"
#include "ScreenTestB.h"

ScreenTestA::ScreenTestA(ScreenManager* manager) : Screen(manager)
{
}

void ScreenTestA::display(sf::RenderWindow& window)
{

	sf::CircleShape circle(100.f);

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed) {
			if(event.key.scancode == sf::Keyboard::Scan::Escape)
				manager_->back();
			if (event.key.scancode == sf::Keyboard::Scan::Q)
				manager_->addStack(new ScreenTestB(manager_));
		}
				
	}

	window.clear();
	window.draw(circle);
	window.display();
	
}
