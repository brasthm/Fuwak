#include "ScreenTestUI.h"

#include "ScreenManager.h"
#include "ScreenTestAnim.h"
#include "ScreenEditMap.h"
#include "../Model/UI/UIRichText.h"
#include "../Model/UI/UIDialog.h"
#include "../EventHandler/EventHandler.h"


class EventResponseSwapToScreenTestUI2 : public EventResponse {
public:
	EventResponseSwapToScreenTestUI2(ScreenTestUI* uiScreen) : uiScreen_(uiScreen) {};
	void execute() override {
		uiScreen_->swapToTestScreen2();
	}
private:
	ScreenTestUI* uiScreen_;
};

class EventResponseSwapToScreenAnim : public EventResponse {
public:
	EventResponseSwapToScreenAnim(ScreenTestUI* uiScreen) : uiScreen_(uiScreen) {};
	void execute() override {
		uiScreen_->swapToAnim();
	}
private:
	ScreenTestUI* uiScreen_;
};

class EventResponseSwapToScreenEdit : public EventResponse {
public:
	EventResponseSwapToScreenEdit(ScreenTestUI* uiScreen) : uiScreen_(uiScreen) {};
	void execute() override {
		uiScreen_->swapToEdit();
	}
private:
	ScreenTestUI* uiScreen_;
};

class EventResponsePopScreenStack : public EventResponse {
public:
	EventResponsePopScreenStack(ScreenTestUI* uiScreen) : uiScreen_(uiScreen) {};
	void execute() override {
		uiScreen_->popScreen();
	}
private:
	ScreenTestUI* uiScreen_;
};


ScreenTestUI::~ScreenTestUI()
{
	
}

void ScreenTestUI::swapToTestScreen2()
{
	manager_->addStack(new ScreenTestUI(manager_));
}

void ScreenTestUI::swapToAnim()
{
	manager_->addStack(new ScreenTestAnim(manager_));
}

void ScreenTestUI::swapToEdit()
{
	manager_->addStack(new ScreenEditMap(manager_));
}

void ScreenTestUI::popScreen()
{
	manager_->back();
}

ScreenTestUI::ScreenTestUI(ScreenManager* manager) : Screen(manager)
{
	UIDialog* d = new UIDialog(manager_->getUIModel(), "Test", 100, 370, 500, 500);
	d->addCore(new UIRichText(manager_->getUIModel(), 100, 370, 490, 400, "#h Bonjour\n#r Ceci est un #b test. #r Lorem ipsum dolor sit amet, consectetur #b adipiscing #r elit. Aliquam et #u auctor neque. #r Vestibulum dignissim odio #i nec metus tempus, eget viverra augue pretium. Suspendisse consectetur imperdiet efficitur. Mauris blandit fermentum diam ut condimentum. #r Quisque  justo quam, iaculis eu rhoncus nec, ultrices sit amet mi. Nullam eu dui lectus. #c 0xff0000ff #b Etiam consequat, #r libero eget sollicitudin #st malesuada, #r massa purus sagittis nisi, vel imperdiet elit #bdiam vel ipsum. Duis molestie faucibus auctor. Proin id ante in quam viverra fermentum quis eu purus. Quisque pulvinar dapibus mi, id ullamcorper diam convallis id. Etiam imperdiet neque at est sodales, et porta mauris suscipit."));
	d->addButtons("Anim", new EventResponseSwapToScreenAnim(this));
	d->addButtons("Edit", new EventResponseSwapToScreenEdit(this));
	d->addButtons("Quitter", new EventResponseCloseDialog(manager_->getUIModel()));

	uiState_->componants->emplace_back(d);

	UIDialog* d2 = new UIDialog(manager_->getUIModel(), "Test2", 10, 10, 500, 500);
	d2->addCore(new UIRichText(manager_->getUIModel(), 100, 370, 490, 400, "Blblblbl"));
	d2->addButtons("Back", new EventResponsePopScreenStack(this));
	d2->addButtons("Swap", new EventResponseSwapToScreenTestUI2(this));
	d2->addButtons("Close", new EventResponseCloseDialog(manager_->getUIModel()));

	uiState_->componants->emplace_back(d2);
}