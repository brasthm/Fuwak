#ifndef FUWAK_BATTLE_ENTITY_H
#define FUWAK_BATTLE_ENTITY_H

#include <string>
#include <SFML/Graphics.hpp>

#include "Map.h"


template<typename T>
class BattleStatistic {
public:
	void reset() {
		current_ = maximum_;
	}
	void add(T value) {
		current_ += value;
		if (current_ > maximum_) current_ = maximum_;
	}
	void sub(T value) {
		current_ -= value;
		if (current_ < 0) current_ = 0;
	}
	T current() {
		return current_;
	}
private:
	T current_, maximum_;
};

class CombatDisplayer;

class BattleEntity
{
public:
	BattleEntity();
	void draw(CombatDisplayer* displayer, Map *map);
	std::string getIconTextureString();
	sf::Vector2f getPosition();
	sf::Vector2u getIconSize();

private:
	std::string name_, textureIconPath_;
	BattleStatistic<int> healthPoint_, abilityPoint_;
	BattleStatistic<float> mouvementPoint_;
	sf::Vector2f position_;
	sf::Vector2u iconSize_;
};


#endif // !FUWAK_BATTLE_ENTITY_H




