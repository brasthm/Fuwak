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


class ElapsedTime {
private:
    sf::Time elapsed_;
    sf::Clock clock_;

    inline static ElapsedTime *elapsedInstance_;

    ElapsedTime() {
        clock_.restart();
    };

    inline ~ElapsedTime() {
        delete elapsedInstance_;
    };

    inline static ElapsedTime *getInstance() {
        if (!elapsedInstance_)
            elapsedInstance_ = new ElapsedTime();
        return elapsedInstance_;
    };



    void tick_() {
        clock_.restart();
    };

    void tock_() {
        elapsed_ = clock_.getElapsedTime();
    }

    sf::Time get_() {
        return elapsed_;
    }



public:
    inline static void tick() {
        getInstance()->tick_();
    };

    inline static void tock() {
        getInstance()->tock_();
    };

    inline static sf::Time get() {
        return getInstance()->get_();
    }


    ElapsedTime(const ElapsedTime&) = delete;
    ElapsedTime& operator= (const ElapsedTime) = delete;

};

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
