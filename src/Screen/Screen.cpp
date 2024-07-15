#include "Screen.h"

Screen::Screen(ScreenManager* manager)
{
	manager_ = manager;
	uiState_ = new UIState();
}

Screen::~Screen()
{
	delete uiState_;
}

UIState* Screen::getState()
{
	return uiState_;
}

