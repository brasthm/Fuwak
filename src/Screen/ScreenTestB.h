#ifndef FUWAK_SCREENTESTB_H
#define FUWAK_SCREENTESTB_H

#include "Screen.h"

class ScreenTestB :
    public Screen
{
public:
    ScreenTestB(ScreenManager* manager);

    void display(sf::RenderWindow& window) override;

};

#endif
