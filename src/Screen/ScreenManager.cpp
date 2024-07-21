#include "ScreenManager.h"

#include "ScreenTestUI.h"
#include "../main.h"

ScreenManager::ScreenManager()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window_.create(sf::VideoMode(WINDOW_W, WINDOW_H), "Fuwak", sf::Style::Default, settings);
	window_.setSize(sf::Vector2u(1280, 720));
	
	sfmlEventHandler_ = new SFMLEventHandler();
	eventDispatcher_ = new EventDispatcher();
	uiDisplayer_ = new UIDisplayer();
	combatDisplayer_ = new CombatDisplayer();


	uiModel_ = new UIModel(eventDispatcher_);
	combatModel_ = new CombatModel(eventDispatcher_);
	eventLogger_ = new EventLogger(eventDispatcher_);

	eventLogger_->logKeyboardEvent();
	eventLogger_->logMouseButtonEvent();
	//eventLogger_->logMouseMouvementEvent();

	sfmlEventHandler_->setNext(eventDispatcher_);

	eventDispatcher_->subscribe(eventLogger_);
	eventDispatcher_->subscribe(uiModel_);
	eventDispatcher_->subscribe(combatModel_);

	addStack(new ScreenTestUI(this));
}

ScreenManager::~ScreenManager()
{
	delete sfmlEventHandler_;
	delete eventDispatcher_;

	delete uiDisplayer_;
	delete combatDisplayer_;

	delete uiModel_;
	delete combatModel_;
	delete eventLogger_;

	for (auto s : stack_) {
		delete s;
	}
	stack_.clear();
}

void ScreenManager::display()
{
	bool quit = false;
	while (!quit && !stack_.empty()) {
		quit = sfmlEventHandler_->pollEvent(window_);

		combatModel_->render(combatDisplayer_);
		uiModel_->render(uiDisplayer_);

		window_.clear();
		combatDisplayer_->display(window_);
		stack_.back()->display(window_);
		uiDisplayer_->display(window_);
		window_.display();

		sf::sleep(sf::milliseconds(5));
	}
}

void ScreenManager::addStack(Screen* screen)
{
	stack_.emplace_back(screen);
	uiModel_->setState(stack_.back()->getState());
}

void ScreenManager::skipStack(Screen* screen)
{
	back();
	addStack(screen);
}


void ScreenManager::back()
{
	delete stack_.back();
	stack_.pop_back();

	if(!stack_.empty())
		uiModel_->setState(stack_.back()->getState());
}

EventDispatcher* ScreenManager::getDispatcher()
{
	return eventDispatcher_;
}

UIModel* ScreenManager::getUIModel()
{
	return uiModel_;
}

CombatModel* ScreenManager::getCombatModel()
{
	return combatModel_;
}
