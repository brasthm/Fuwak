#ifndef FUWAK_MASTERDISPLAYER_H
#define FUWAK_MASTERDISPLAYER_H

#include "CombatDisplayer.h"
#include "UIDisplayer.h"

class MasterDisplayer
{
public:
	MasterDisplayer();
	~MasterDisplayer();
private:
	std::vector<Displayer*> displayers_;
};

#endif