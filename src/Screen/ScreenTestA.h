#ifndef FUWAK_SCREENTESTA_H
#define FUWAK_SCREENTESTA_H

#include "Screen.h"

class ScreenTestA :
    public Screen
{
public:
    ScreenTestA(ScreenManager* manager);

    void display(sf::RenderWindow& window) override;


private:
};

#endif

