#include "ScreenTestAnim.h"

#include "../Model/UI/UIHorizontalStacker.h"
#include "../Model/UI/UIButton.h"

#include "../EventHandler/EventHandler.h"
#include "ScreenManager.h"

class EventResponsePopScreenStack : public EventResponse {
public:
	EventResponsePopScreenStack(ScreenTestAnim* animScreen) : animScreen_(animScreen) {};
	void execute() override {
		animScreen_->popScreen();
	}
private:
	ScreenTestAnim* animScreen_;
};

class EventResponseSwapSprite : public EventResponse {
public:
	EventResponseSwapSprite(ScreenTestAnim* animScreen) : animScreen_(animScreen) {};
	void execute() override {
		animScreen_->change();
	}
private:
	ScreenTestAnim* animScreen_;
};

class EventResponseRetryAnim : public EventResponse {
public:
	EventResponseRetryAnim(ScreenTestAnim* animScreen) : animScreen_(animScreen) {};
	void execute() override {
		animScreen_->restart();
	}
private:
	ScreenTestAnim* animScreen_;
};

ScreenTestAnim::ScreenTestAnim(ScreenManager* manager) : Screen(manager),
	size_(EaseOutExpo), rotation_(EaseInLinear), iconPosition_(EaseInLinear), idlePosition_(EaseOutBack)
{
	UIHorizontalStacker* buttons = new UIHorizontalStacker(manager_->getUIModel(),  0, 0, 1000, 100);

	buttons->add(new UIButton(manager_->getUIModel(), "Back", 0, 0, 300, 100, 
		sf::Color::Green, sf::Color::Green, new EventResponsePopScreenStack(this)));

	buttons->add(new UIButton(manager_->getUIModel(), "Change", 0, 0, 300, 100,
		sf::Color::Green, sf::Color::Green, new EventResponseSwapSprite(this)));

	buttons->add(new UIButton(manager_->getUIModel(), "Retry", 0, 0, 300, 100,
		sf::Color::Green, sf::Color::Green, new EventResponseRetryAnim(this)));

	uiState_->componants->emplace_back(buttons);

	myrtille_.loadFromFile(RessourceLoader::getPath("Sprites/MyrtilleCombat.png"));
	portrait_.loadFromFile(RessourceLoader::getPath("Sprites/MyrtilleCombat.png"), sf::IntRect(600, 135, 390, 390));
	idle_.setTexture(myrtille_);
	icon_.setTexture(portrait_);
	icon_.setOrigin(195, 195);
	idle_.setScale(0.7, 0.7);

	restart();
}

ScreenTestAnim::~ScreenTestAnim()
{
}

void ScreenTestAnim::popScreen()
{
	manager_->back();
}

void ScreenTestAnim::display(sf::RenderWindow& window)
{
	icon_.setScale(size_.get(), size_.get());
	icon_.setRotation(rotation_.get());
	icon_.setPosition(iconPosition_.get());

	idle_.setPosition(idlePosition_.get());

	if (drawIcon_) window.draw(icon_);
	else window.draw(idle_);
}

void ScreenTestAnim::restart()
{
	size_.setInstant(0);
	size_.set(0.7, 1);
	rotation_.setInstant(5);
	rotation_.set(10, 3);
	iconPosition_.setInstant(sf::Vector2f(500, 500));
	iconPosition_.set(sf::Vector2f(550, 520), 3);

	idlePosition_.setInstant(sf::Vector2f(-idle_.getGlobalBounds().width, 0));
	idlePosition_.set(sf::Vector2f(0, 0), 1);
}

void ScreenTestAnim::change()
{
	drawIcon_ = !drawIcon_;
}
