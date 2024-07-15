#ifndef FUWAK_UI_PANEL_H
#define FUWAK_UI_PANEL_H

#include "UIContainer.h"

class UIPanel :
    public UIContainer
{
public:
    UIPanel(UIModel* model, float x, float y, float w, float h, sf::Color backgroundColor, int outlineThickness, sf::Color outlineColor);
    void draw(UIDisplayer* displayer) override;
    int getOutlineThickness();
    sf::Color getBackgroundColor();
    sf::Color getOutlineColor();

private:
    sf::Color backgroundColor_, outlineColor_;
    int outlineThickness_;

    

};

#endif

