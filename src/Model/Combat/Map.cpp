#include "Map.h"

#include "../../main.h"
#include "../../System/Utils.h"
#include "../../Displayer/CombatDisplayer.h"

#include <iostream>

static constexpr float MAP_ZOOM_SPEED = 0.07;
static constexpr float MAP_ZOOM_LIMIT_MIN = 0.3;
static constexpr float MAP_ZOOM_LIMIT_MAX = 3;

Map::Map() : view_(sf::FloatRect(0, 0, WINDOW_W, WINDOW_H))
{
	texture_ = "Maps/Forest Clearing (digital, day).jpg";

	textureSize_ = RessourceLoader::getTexture(texture_)->getSize();
}

void Map::draw(CombatDisplayer* displayer)
{
	displayer->displayMap(this);
}

sf::View Map::getView()
{
	return view_;
}

std::string Map::getTextureString()
{
	return texture_;
}

sf::Vector2u Map::getTextureSize()
{
	return textureSize_;
}

void Map::zoom(sf::Vector2f mouseView, float zoom)
{
	sf::Vector2f delta = mouseView - view_.getCenter();

	view_.zoom(1 - zoom * MAP_ZOOM_SPEED);

	if (view_.getSize().x < WINDOW_W * MAP_ZOOM_LIMIT_MIN) {
		view_.setSize(WINDOW_W * MAP_ZOOM_LIMIT_MIN, WINDOW_H * MAP_ZOOM_LIMIT_MIN);
	}
	else if (view_.getSize().x > WINDOW_W * MAP_ZOOM_LIMIT_MAX) {
		view_.setSize(WINDOW_W * MAP_ZOOM_LIMIT_MAX, WINDOW_H * MAP_ZOOM_LIMIT_MAX);
	}

	//view_.move(delta);
	
}

void Map::move(sf::Vector2f mouseView)
{
	sf::Vector2f center = mouseView - oldMouseView_;

	view_.setCenter(view_.getCenter() - center);
}

void Map::setOldMouseView(sf::Vector2f mouseView)
{
	oldMouseView_ = mouseView;
}

void Map::resetDragMouvement()
{
	
}
