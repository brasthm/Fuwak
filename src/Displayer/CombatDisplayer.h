#ifndef FUWAK_COMBAT_DISPLAYER_H
#define FUWAK_COMBAT_DISPLAYER_H

#include "Displayer.h"

#include "../Model/Combat/Map.h" 

class CombatDisplayer :
    public Displayer
{
public:
    void displayMap(Map* map);
};

#endif
