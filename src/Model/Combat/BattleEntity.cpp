#include "BattleEntity.h"

#include "../../Displayer/CombatDisplayer.h"
#include "../../Screen/ScreenManager.h"

#include <iostream>

BattleEntity::BattleEntity()
{
	textureIconPath_ = "Characters/BattleIcons/Erwan.png";
	iconSize_.x = 100;
	iconSize_.y = 100;
	speed_ = 500;
}

void BattleEntity::draw(CombatDisplayer* displayer, Map *map)
{
	displayer->displayBattleEntity(this, map);
}

std::string BattleEntity::getIconTextureString()
{
	return textureIconPath_;
}

sf::Vector2f BattleEntity::getPosition()
{
	return position_;
}

sf::Vector2u BattleEntity::getIconSize()
{
	return iconSize_;
}

void BattleEntity::move(sf::Vector2f delta) {
    position_ += ElapsedTime::get().asSeconds() * delta * speed_;
}
