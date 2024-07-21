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
	void setObstaclePoint(sf::Vector2f point);
	void newObstacle();
	void removeLastObstacle();
	void clearGroup();
	void save();
	void load(const std::string &path);

	void toggleEdit();

	std::vector<std::vector<sf::Vector2f>>* getObstacles();

private:
	std::string texture_, mapfile_;
	sf::View view_;
	sf::Vector2u textureSize_;
	sf::Vector2f oldMouseView_;

	bool toggleEdit_;

	std::vector<std::vector<sf::Vector2f>> obstacles_;
};


#endif;
