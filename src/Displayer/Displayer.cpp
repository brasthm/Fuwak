#include "Displayer.h"
#include "../System/RessourceLoader.h"
#include "../main.h"

Displayer::~Displayer()
{

}

void Displayer::display(sf::RenderWindow& window)
{
	for (auto& group : groups_) {
		window.setView(group.view);

		if (group.triangles.size() != 0)
			window.draw(&group.triangles[0], group.triangles.size(), sf::Triangles, group.state);

		for (auto& text : group.texts)
			window.draw(text);
	}
	
}

void Displayer::drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color c1)
{
	drawTriangle(p1, p2, p3, c1, c1, c1);
}

void Displayer::drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color c1, sf::Color c2, sf::Color c3)
{
	groups_.back().triangles.emplace_back(p1, c1);
	groups_.back().triangles.emplace_back(p2, c2);
	groups_.back().triangles.emplace_back(p3, c3);
}

void Displayer::drawQuad(float x, float y, float w, float h, sf::Color backgroundColor, float thickness, sf::Color outlineColor)
{
	sf::Vector2f p1(x, y), p2(x + w, y), p3(x, y + h), p4(x + w, y + h);
	drawTriangle(p1, p2, p3, backgroundColor);
	drawTriangle(p2, p3, p4, backgroundColor);
	if (thickness == 0)
		return;

	float c = SQRT2 * thickness;
	sf::Vector2f o1(x - c, y - c), o2(x + w + c, y - c), 
		o3(x - c, y + h + c), o4(x + w + c, y + h + c);

	drawTriangle(p1, o1, o2, outlineColor);
	drawTriangle(p1, p2, o2, outlineColor);

	drawTriangle(p2, o2, o4, outlineColor);
	drawTriangle(p2, p4, o4, outlineColor);

	drawTriangle(p3, o1, o3, outlineColor);
	drawTriangle(p3, p1, o1, outlineColor);

	drawTriangle(p4, o4, o3, outlineColor);
	drawTriangle(p4, p3, o3, outlineColor);
}

void Displayer::drawText(float x, float y, float w, float h, std::string& str, int size, sf::Text::Style style, sf::Color color, int outlineThickness, sf::Color outlineColor)
{
	sf::Text text;
	text.setFont(RessourceLoader::getFont("Font/Oxanium/Oxanium-Regular.ttf"));
	text.setString(str);
	text.setCharacterSize(size);
	text.setStyle(style);
	text.setFillColor(color);
	text.setOutlineColor(outlineColor);
	text.setOutlineThickness(outlineThickness);
	text.setPosition(x, y);

	std::string loopstr = str;
	while (text.getGlobalBounds().width > w && !loopstr.empty()) {
		text.setString(loopstr + "...");
		loopstr = loopstr.erase(loopstr.size() - 1, 1);
	}

	if(!loopstr.empty())
		groups_.back().texts.push_back(text);
}

void Displayer::drawQuad(float x, float y, float w, float h, float xt, float yt, float wt, float ht)
{
	sf::Vector2f p1(x, y), p2(x + w, y), p3(x, y + h), p4(x + w, y + h);
	sf::Vector2f t1(xt, yt), t2(xt + wt, yt), t3(xt, yt + ht), t4(xt + wt, yt + ht);
	drawTriangle(p1, p2, p3, t1, t2, t3);
	drawTriangle(p2, p3, p4, t2, t3, t4);
}

void Displayer::drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f t1, sf::Vector2f t2, sf::Vector2f t3)
{
	groups_.back().triangles.emplace_back(p1, t1);
	groups_.back().triangles.emplace_back(p2, t2);
	groups_.back().triangles.emplace_back(p3, t3);
}

void Displayer::clear()
{
	groups_.clear();
}

void Displayer::newGroup()
{
	groups_.emplace_back();
}

void Displayer::newGroup(sf::View view)
{
	groups_.emplace_back(view);
}

void Displayer::newGroup(sf::View view, const std::string& textureStrting)
{
	groups_.emplace_back(view, textureStrting);
}
