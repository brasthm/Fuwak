#ifndef FUWAK_UI_DISPLAYER_H
#define FUWAK_UI_DISPLAYER_H

#include "Displayer.h"

#include "../Model/UI/UIComponant.h"
#include "../Model/UI/UIButton.h"
#include "../Model/UI/UIText.h"
#include "../Model/UI/UIPanel.h"

class UIDisplayer :
    public Displayer
{
public:
    void drawComponant(UIComponant *comp);

    void drawComponant(UIButton* comp);
    void drawComponant(UIText* comp);
    void drawComponant(UIPanel* comp);
};
#endif
