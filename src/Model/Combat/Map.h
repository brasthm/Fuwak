#ifndef FUWAK_MAP_H
#define FUWAK_MAP_H

#include <SFML/Graphics.hpp>

class CombatDisplayer;

class Map
{
public:
	Map();
	void draw(CombatDisplayer* displayer);

	sf::View getView();
	std::string getTextureString();
	sf::Vector2u getTextureSize();

	void zoom(sf::Vector2f mouseView, float zoom);
	void move(sf::Vector2f mouseView);
	void setOldMouseView(sf::Vector2f mouseView);
	void resetDragMouvement();

private:
	std::string texture_;
	sf::View view_;
	sf::Vector2u textureSize_;
	sf::Vector2f oldMouseView_;
};


#endif;
