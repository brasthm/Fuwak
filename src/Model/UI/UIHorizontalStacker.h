#ifndef FUWAK_UI_HORIZONTALSTACKER_H
#define FUWAK_UI_HORIZONTALSTACKER_H

#include "UIContainer.h"
class UIHorizontalStacker :
    public UIContainer
{
public:
    UIHorizontalStacker(UIModel* model, float x, float y, float w, float h) :
        UIContainer(model, x, y, w, h) {};
    void add(UIComponant* comp) override;
    void resize(float w, float h) override;
};
#endif
