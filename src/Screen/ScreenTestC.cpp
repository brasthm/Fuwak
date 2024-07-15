#include "ScreenTestC.h"
#include "ScreenManager.h"

ScreenTestC::ScreenTestC(ScreenManager* manager) : Screen(manager)
{
}

void ScreenTestC::display(sf::RenderWindow& window)
{

	sf::CircleShape circle(100.f);
	circle.setPointCount(3);


	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.scancode == sf::Keyboard::Scan::Escape)
				manager_->back();
		}
	}

	window.clear();
	window.draw(circle);
	window.display();

}
