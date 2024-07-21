#include "ScreenEditMap.h"

#include "../Model/UI/UIHorizontalStacker.h"
#include "../Model/UI/UIButton.h"

#include "ScreenManager.h"

class EventResponsePopScreenStack : public EventResponse {
public:
	EventResponsePopScreenStack(ScreenEditMap* animScreen) : animScreen_(animScreen) {};
	void execute() override {
		animScreen_->popScreen();
	}
private:
	ScreenEditMap* animScreen_;
};

class EventResponseToggleEdit : public EventResponse {
public:
	EventResponseToggleEdit(ScreenEditMap* screen) : screen_(screen) {};
	void execute() override {
		screen_->toggle();
	}
private:
	ScreenEditMap* screen_;
};

class EventResponseNewGroup : public EventResponse {
public:
	EventResponseNewGroup(ScreenEditMap* screen) : screen_(screen) {};
	void execute() override {
		screen_->newGroup();
	}
private:
	ScreenEditMap* screen_;
};

class EventResponseRemove : public EventResponse {
public:
	EventResponseRemove(ScreenEditMap* screen) : screen_(screen) {};
	void execute() override {
		screen_->removeLast();
	}
private:
	ScreenEditMap* screen_;
};

class EventResponseClear : public EventResponse {
public:
	EventResponseClear(ScreenEditMap* screen) : screen_(screen) {};
	void execute() override {
		screen_->removeGroup();
	}
private:
	ScreenEditMap* screen_;
};

class EventResponseSave : public EventResponse {
public:
	EventResponseSave(ScreenEditMap* screen) : screen_(screen) {};
	void execute() override {
		screen_->saveMap();
	}
private:
	ScreenEditMap* screen_;
};

ScreenEditMap::ScreenEditMap(ScreenManager* manager) : Screen(manager) {
	UIHorizontalStacker* buttons = new UIHorizontalStacker(manager_->getUIModel(), 0, 0, 1000, 100);

	buttons->add(new UIButton(manager_->getUIModel(), "Back", 0, 0, 300, 100,
		sf::Color::Red, sf::Color::Green, new EventResponsePopScreenStack(this)));

	buttons->add(new UIButton(manager_->getUIModel(), "New", 0, 0, 300, 100,
		sf::Color::Red, sf::Color::Green, new EventResponseNewGroup(this)));

	buttons->add(new UIButton(manager_->getUIModel(), "Toggle", 0, 0, 300, 100,
		sf::Color::Red, sf::Color::Green, new EventResponseToggleEdit(this)));

	buttons->add(new UIButton(manager_->getUIModel(), "Remove", 0, 0, 300, 100,
		sf::Color::Red, sf::Color::Green, new EventResponseRemove(this)));

	buttons->add(new UIButton(manager_->getUIModel(), "Clear", 0, 0, 300, 100,
		sf::Color::Red, sf::Color::Green, new EventResponseClear(this)));

	buttons->add(new UIButton(manager_->getUIModel(), "Save", 0, 0, 300, 100,
		sf::Color::Red, sf::Color::Green, new EventResponseSave(this)));

	uiState_->componants->emplace_back(buttons);
}

ScreenEditMap::~ScreenEditMap()
{
}

void ScreenEditMap::toggle()
{
	manager_->getCombatModel()->toggleMapObstacles();
}

void ScreenEditMap::newGroup()
{
	manager_->getCombatModel()->newMapObstaclesGroup();
}

void ScreenEditMap::removeLast()
{
	manager_->getCombatModel()->removeLastPoint();
}

void ScreenEditMap::removeGroup()
{
	manager_->getCombatModel()->clearMapObstacleGroup();
}

void ScreenEditMap::popScreen()
{
	manager_->back();
}

void ScreenEditMap::saveMap()
{
	manager_->getCombatModel()->saveMapPoint();
}
