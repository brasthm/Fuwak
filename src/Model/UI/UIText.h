#ifndef FUWAK_UI_TEXT_H
#define FUWAK_UI_TEXT_H


#include "UIComponant.h"
class UIText :
    public UIComponant
{
public:
    UIText(UIModel* model, const std::string &text, sf::Text::Style style, int size, float x, float y, float w, float h,
        sf::Color textColor=sf::Color::White, int oulineThickness=0, sf::Color outlineColor=sf::Color::Black);

    void draw(UIDisplayer* displayer) override;
    sf::Color getTextColor();
    sf::Color getOutlineColor();
    sf::Text::Style getStyle();
    int getSize();
    int getOutlineThickness();
    std::string &getText();
private:
    sf::Text::Style style_;
    std::string text_;
    sf::Color textColor_;
    sf::Color outlineColor_;
    int size_, outlineThickness_;
};

#endif