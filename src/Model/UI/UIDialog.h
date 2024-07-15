#ifndef FUWAK_UI_DIALOG_H
#define FUWAK_UI_DIALOG_H

#include "UIContainer.h"
#include "UIHorizontalStacker.h"
#include "UIVerticalStacker.h"

#include "UIPanel.h"


class UIDialog :
    public UIContainer
{
public:
    UIDialog(UIModel* model, const std::string &name, float x, float y, float w, float h);
    void addCore(UIComponant* comp);
    void addButtons(const std::string &text, EventResponse *rep = nullptr);

    void recieve(MouseLeftDragEvent* ev, EventResponse** rep) override;
    void recieve(MouseLeftClickEvent* ev, EventResponse** rep) override;
    void recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep) override;

private:
    void add(UIComponant* comp) override;
    float clicPosX_, clicPosY_;
    bool dragged_;

    UIVerticalStacker *core_;
    UIHorizontalStacker* buttons_;
    UIPanel* titlePanel_;
    
};

#endif