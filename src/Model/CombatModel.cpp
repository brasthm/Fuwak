#include "CombatModel.h"

#include <iostream>

CombatModel::CombatModel(EventDispatcher* ed) : EventReciever(ed)
{
	map_ = new Map();
}

CombatModel::~CombatModel()
{
	delete map_;
}

void CombatModel::render(CombatDisplayer* combatDisplayer)
{
	combatDisplayer->clear();
	map_->draw(combatDisplayer);
}

void CombatModel::recieve(MouseMoveEvent* ev, EventResponse** rep)
{
	map_->setOldMouseView(ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), map_->getView()));
}

void CombatModel::recieve(MouseLeftDragEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), map_->getView());
	map_->move(pos);
	map_->setOldMouseView(ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), map_->getView()));
}

void CombatModel::recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep)
{
	
}

void CombatModel::recieve(MouseWheelScrollEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), map_->getView());
	map_->zoom(pos, ev->delta());
}
