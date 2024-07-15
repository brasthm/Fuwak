#ifndef FUWAK_SCREEN_H
#define FUWAK_SCREEN_H

#include <SFML/Graphics.hpp>

#include "../Model/UIModel.h"

class ScreenManager;

class Screen
{
public: 
	Screen(ScreenManager* manager);
	~Screen();
	UIState* getState();
	virtual void display(sf::RenderWindow &window) {};

protected:
	ScreenManager* manager_;
	UIState* uiState_;
};

#endif
