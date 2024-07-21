#ifndef FUWAK_SCREENMANAGER_H
#define FUWAK_SCREENMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Screen.h"

//Model
#include"../Model/UIModel.h"
#include"../Model/CombatModel.h"

//View
#include "../Displayer/UIDisplayer.h"
#include "../Displayer/CombatDisplayer.h"

//Controller
#include "../EventHandler/SFMLEventHandler.h"
#include "../EventHandler/EventDispatcher.h"
#include "../EventHandler/EventReciever.h"
#include "../EventHandler/EventLogger.h"




class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();

	void display();
	void addStack(Screen* screen);
	void skipStack(Screen* screen);
	void back();
	


	EventDispatcher* getDispatcher();
	UIModel* getUIModel();
	CombatModel* getCombatModel();

private:
	std::vector<Screen*> stack_;
	sf::RenderWindow window_;

	UIModel *uiModel_;
	CombatModel* combatModel_;

	UIDisplayer* uiDisplayer_;
	CombatDisplayer* combatDisplayer_;

	SFMLEventHandler* sfmlEventHandler_;
	EventDispatcher* eventDispatcher_;

	EventLogger* eventLogger_;

};

#endif
