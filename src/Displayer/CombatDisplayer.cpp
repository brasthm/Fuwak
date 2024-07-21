#include "CombatDisplayer.h"

#include <list>

void CombatDisplayer::displayMap(Map* map)
{
	auto size = map->getTextureSize();

	newGroup(map->getView(), map->getTextureString());
	drawQuad(0, 0, size.x, size.y, 0, 0, size.x, size.y);

	newGroup(map->getView());
	auto obstacles = map->getObstacles();

	for (int i = 0; i < obstacles->size(); i++) {
		std::list<sf::Vector2f> triangle;
		for (int j = 0; j < obstacles->at(i).size(); j++) {
			triangle.push_back(obstacles->at(i)[j]);
			if (triangle.size() == 3) {
				drawTriangle(*triangle.begin(), *(++triangle.begin()), *(++++triangle.begin()), sf::Color(255, 0, 0, 128));

				triangle.pop_front();
			}
		}
	}
}
