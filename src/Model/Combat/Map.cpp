#include "Map.h"

#include "../../main.h"
#include "../../System/Utils.h"
#include "../../Displayer/CombatDisplayer.h"

#include <iostream>
#include <fstream>

static constexpr float MAP_ZOOM_SPEED = 0.07;
static constexpr float MAP_ZOOM_LIMIT_MIN = 0.3;
static constexpr float MAP_ZOOM_LIMIT_MAX = 3;

Map::Map() : view_(sf::FloatRect(0, 0, WINDOW_W, WINDOW_H))
{
	load("Maps/Forest Clearing (digital, day)");

	toggleEdit_ = false;

	obstacles_.emplace_back();

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

void Map::setObstaclePoint(sf::Vector2f point)
{
	if(toggleEdit_)
		obstacles_.back().push_back(point);
}

void Map::newObstacle()
{
	if (toggleEdit_)
		obstacles_.emplace_back();
}

void Map::removeLastObstacle()
{
	if (obstacles_.back().size() > 0)
		obstacles_.back().pop_back();
}

void Map::clearGroup()
{
	if (obstacles_.size() > 0)
		obstacles_.pop_back();
	if (obstacles_.size() == 0)
		obstacles_.emplace_back();
}

void Map::save()
{
	std::ofstream mapfile(mapfile_);

	std::cout << mapfile_ << std::endl;

	mapfile << texture_ << std::endl;

	for (auto group : obstacles_) {
		for (auto point : group) {
			mapfile << point.x << " " << point.y << " ";
		}
		mapfile << std::endl;
	}
}

void Map::load(const std::string& path)
{
	mapfile_ = RessourceLoader::getPath(path)+ ".txt";

	std::ifstream mapfile(mapfile_);

	
	std::getline(mapfile, texture_);
	std::string line;
	while (std::getline(mapfile, line)) {
		obstacles_.emplace_back();
		auto lines = Utils::split(line, ' ');
		for (int i = 0; i < lines.size() / 2; i++) {
			obstacles_.back().emplace_back(std::stof(lines[2 * i]), std::stof(lines[2 * i + 1]));
		}
	}	
}

void Map::toggleEdit()
{
	toggleEdit_ = !toggleEdit_;

	std::string res = toggleEdit_ ? "true" : "false";

	std::cout << "Map::toggleEdit : status " << res << std::endl;
}

std::vector<std::vector<sf::Vector2f>>* Map::getObstacles()
{
	return &obstacles_;
}
