#include "CombatDisplayer.h"

void CombatDisplayer::displayMap(Map* map)
{
	auto size = map->getTextureSize();

	newGroup(map->getView(), map->getTextureString());
	drawQuad(0, 0, size.x, size.y, 0, 0, size.x, size.y);
}
