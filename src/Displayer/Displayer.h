#ifndef FUWAK_DISPLAYER_H
#define FUWAK_DISPLAYER_H

#include <SFML/Graphics.hpp>
#include <map>

#include "../main.h"
#include "../System/RessourceLoader.h"

class DisplayGroup {
public:
	DisplayGroup() : view(DEFAULT_VIEW){};
	DisplayGroup(sf::View v) : view(v) {};
	DisplayGroup(sf::View v, const std::string& t) : view(v){ 
		state.texture = RessourceLoader::getTexture(t);
	};
	std::vector<sf::Vertex> triangles;
	std::vector<sf::Text> texts;
	sf::View view;
	sf::RenderStates state;
};

class Displayer
{
public:
	Displayer() = default;
	~Displayer();
	virtual void display(sf::RenderWindow &window);
	void drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color c1);
	void drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color c1, sf::Color c2, sf::Color c3);
	void drawQuad(float x, float y, float w, float h, sf::Color backgroundColor, float thikness = 0, sf::Color outlineColor = sf::Color::Black);
	void drawText(float x, float y, float w, float h, std::string& str, int size, sf::Text::Style style, sf::Color color,
		int outlineThickness = 0, sf::Color outlineColor = sf::Color::Black);
	void drawQuad(float x, float y, float w, float h, float xt, float yt, float wt, float ht);
	void drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f t1, sf::Vector2f t2, sf::Vector2f t3);
	void clear();
	void newGroup();
	void newGroup(sf::View view);
	void newGroup(sf::View view, const std::string &textureStrting);
protected:
	std::vector<DisplayGroup> groups_;
};

#endif

