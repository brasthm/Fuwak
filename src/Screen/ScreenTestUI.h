#ifndef FUWAK_SCREENTESTUI_H
#define FUWAK_SCREENTESTUI_H


#include "Screen.h"
#include "../EventHandler/EventDispatcher.h"


#include <SFML/Graphics.hpp>


class ScreenTestUI :
    public Screen
{
public:

    ScreenTestUI(ScreenManager* manager);
    ~ScreenTestUI();

    void swapToTestScreen2();
    void swapToAnim();
    void popScreen();
    

private:
    
};

#endif