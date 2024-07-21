#ifndef FUWAK_SCREEN_EDITMAP_H
#define FUWAK_SCREEN_EDITMAP_H

#include "Screen.h"

class ScreenEditMap :
    public Screen
{
public:
    ScreenEditMap(ScreenManager* manager);
    ~ScreenEditMap();

    void toggle();
    void newGroup();
    void removeLast();
    void removeGroup();
    void popScreen();
    void saveMap();

private:

};


#endif // !FUWAK_SCREEN_EDITMAP_H


