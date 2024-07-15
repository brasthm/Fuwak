#ifndef FUWAK_UI_RICHTEXT_H
#define FUWAK_UI_RICHTEXT_H

#include "UIContainer.h"
class UIRichText :
    public UIContainer
{
public:
    UIRichText(UIModel* model, float x, float y, float w, float h, const std::string& str);
private:
    void build(const std::string& str);
    void addComponant(float x, float y, float w, float h, const std::string& str);
	void readParam(char c);
	void readCommand(char c);
	void pushComponant();
	void returnLine();
	void pushWord();


	std::string cur_, param_, mode_, word_;
	bool escapeNext_, store_, readParam_;
	float lastX_, lastY_;
	int size_, lineMaxSize_;
	sf::Text::Style style_;

	int index_, lastIndex_;

	sf::Text dummy_;
	
};

#endif