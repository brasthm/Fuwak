#ifndef FUWAK_SCREEM_TESTANIM_H
#define FUWAK_SCREEM_TESTANIM_H


#include "Screen.h"
#include "../System/Interpolable.h"


class ScreenTestAnim :
    public Screen
{
public:
    ScreenTestAnim(ScreenManager* manager);
    ~ScreenTestAnim();
    void popScreen();
    void display(sf::RenderWindow& window);

    void restart();
    void change();
private:
    sf::Texture myrtille_, portrait_;
    sf::Sprite idle_, icon_;

    IFloat size_, rotation_;
    IVector2f iconPosition_, idlePosition_;

    bool drawIcon_;
};

#endif