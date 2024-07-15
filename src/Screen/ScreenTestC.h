#ifndef FUWAK_SCREENTESTC_H
#define FUWAK_SCREENTESTC_H

#include "Screen.h"


class ScreenTestC :
    public Screen
{
public:
    ScreenTestC(ScreenManager* manager);

    void display(sf::RenderWindow& window) override;
};

#endif

