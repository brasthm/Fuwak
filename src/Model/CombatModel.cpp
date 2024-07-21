#include "CombatModel.h"

#include <iostream>

CombatModel::CombatModel(EventDispatcher* ed) : EventReciever(ed)
{
	map_ = new Map();
	bEntity_ = new BattleEntity();
}

CombatModel::~CombatModel()
{
	delete map_;
	delete bEntity_;
}

void CombatModel::render(CombatDisplayer* combatDisplayer)
{
	combatDisplayer->clear();
	map_->draw(combatDisplayer);
	bEntity_->draw(combatDisplayer, map_);
}

void CombatModel::toggleMapObstacles()
{
	map_->toggleEdit();
}

void CombatModel::newMapObstaclesGroup()
{
	map_->newObstacle();
}

void CombatModel::clearMapObstacleGroup()
{
	map_->clearGroup();
}

void CombatModel::removeLastPoint()
{
	map_->removeLastObstacle();
}

void CombatModel::saveMapPoint()
{
	map_->save();
}

void CombatModel::recieve(MouseMoveEvent* ev, EventResponse** rep)
{
	map_->setOldMouseView(ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), map_->getView()));
}

void CombatModel::recieve(MouseRightClickEvent* ev, EventResponse** rep)
{
	sf::Vector2f pos = ev->window()->mapPixelToCoords(sf::Vector2i(ev->x(), ev->y()), map_->getView());
	map_->setObstaclePoint(pos);
	ev->accept();
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
