#ifndef FUWAK_UI_VERTICALSTACKER_H
#define FUWAK_UI_VERTICALSTACKER_H


#include "UIContainer.h"
class UIVerticalStacker :
    public UIContainer
{
public:
    UIVerticalStacker(UIModel* model, float x, float y, float w, float h) :
        UIContainer(model, x, y, w, h){};
    void add(UIComponant* comp) override;
    void resize(float w, float h) override;

};

#endif