#include "CombatModel.h"

#include <iostream>
#include "../System/Utils.h"

#include <langinfo.h>

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
    move();

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

void CombatModel::recieve(KeyboardHoldEvent *ev, EventResponse **rep) {


    //std::cout << mouvementVector_.x << " " << mouvementVector_.y << std::endl;
}

void CombatModel::move() {
    sf::Vector2f delta;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) {
        delta.y -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
        delta.y += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
        delta.x -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
        delta.x += 1;
    }

    if(delta.x != 0 || delta.y != 0)
        delta = Utils::normalize(delta);
    bEntity_->move(delta);
}
