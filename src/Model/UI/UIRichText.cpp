#include "UIRichText.h"

#include "../../System/RessourceLoader.h"
#include "../../System/Utils.h"
#include "UIText.h"
#include "UIButton.h"

#include <iostream>

static constexpr int RICHTEXT_DEFAULT_SIZE = 20;
static constexpr int RICHTEXT_TITLE_SIZE = 30;
static constexpr int RICHTEXT_INTERLINE_SIZE = 5;

UIRichText::UIRichText(UIModel* model, float x, float y, float w, float h, const std::string& str) :
	UIContainer(model, x, y, w, h)
{
	build(str);
}

void UIRichText::build(const std::string& str)
{
	cur_ = "", param_ = "", mode_ = "", word_ = "";
	escapeNext_ = false, store_ = false, readParam_ = false;
	lastX_ = x_, lastY_ = y_ + RICHTEXT_TITLE_SIZE;
	size_ = RICHTEXT_DEFAULT_SIZE, lineMaxSize_ = RICHTEXT_DEFAULT_SIZE;
	style_ = sf::Text::Style::Regular;

	index_ = 0, lastIndex_ = 0;

	dummy_.setFont(RessourceLoader::getFont("Font/Oxanium/Oxanium-Regular.ttf"));
	dummy_.setCharacterSize(size_);
	dummy_.setStyle(style_);
	dummy_.setPosition(0, 0);

	for (int i = 0; i < str.size(); i++) {
		if (escapeNext_) {
			readCommand(str[i]);
		}
		else if (readParam_) {
			readParam(str[i]);
		}
		else {
			if (str[i] == '#') {
				escapeNext_ = true;
				pushWord();
				pushComponant();
			}
			else if (str[i] == ' ') {
				word_ += ' ';
				pushWord();
			}
			else if (str[i] == '\n') {
				pushWord();
				pushComponant();
				returnLine();
			}
			else{
				word_ += str[i];
			}
		}
	}

	pushWord();
	pushComponant();
}

void UIRichText::addComponant(float x, float y, float w, float h, const std::string& str)
{
	if (index_ == 0) {
		add(new UIText(model_, str, style_, size_, x, y, w, h));
	}
	if (index_ == 1) {
		add(new UIText(model_, str, style_, size_, x, y, w, h, sf::Color(Utils::stui(param_))));
	}
	if (index_ == 2) {
		add(new UIButton(model_, str, x, y, w, h, sf::Color::Red, sf::Color::White));
	}
}

void UIRichText::readParam(char c)
{
	if (c == ' ') {
		readParam_ = false;
		
		if (index_ == 2) {
			dummy_.setString("Debuff " + param_);
			dummy_.setCharacterSize(RICHTEXT_DEFAULT_SIZE);
			dummy_.setStyle(sf::Text::Style::Regular);

			cur_ = "Debuff " + param_;

			pushComponant();
			index_ = lastIndex_;
		}
	}
	else
		param_ += c;
}

void UIRichText::readCommand(char c)
{

	if (c == ' ') {
		escapeNext_ = false;

		if (mode_ == "r") {
			size_ = RICHTEXT_DEFAULT_SIZE;
			style_ = sf::Text::Style::Regular;
			index_ = 0;
			param_ = "";
		}
		if (mode_ == "b") {
			style_ = sf::Text::Style::Bold;
		}
		if (mode_ == "i") {
			style_ = sf::Text::Style::Italic;
		}
		if (mode_ == "u") {
			style_ = sf::Text::Style::Underlined;
		}
		if (mode_ == "st") {
			style_ = sf::Text::Style::StrikeThrough;
		}
		if (mode_ == "h") {
			size_ = RICHTEXT_TITLE_SIZE;
			style_ = sf::Text::Style::Bold;
		}
		if (mode_ == "c") {
			readParam_ = true;
			param_ = "";
			index_ = 1;
		}
		if (mode_ == "d") {
			readParam_ = true;
			param_ = "";
			lastIndex_ = index_;
			index_ = 2;
		}

		mode_ = "";
	}
	else {
		mode_ += c;
	}
	
}

void UIRichText::pushWord()
{
	dummy_.setString(cur_ + word_);
	dummy_.setCharacterSize(size_);
	dummy_.setStyle(style_);

	if (lastX_ + dummy_.getGlobalBounds().width + dummy_.getGlobalBounds().left > x_ + w_) {
		pushComponant();
		returnLine();
	}
	cur_ += word_;
	word_ = "";
}

void UIRichText::pushComponant()
{
	if (cur_.empty())
		return;

	
	dummy_.setString(cur_);
	dummy_.setCharacterSize(size_);
	dummy_.setStyle(style_);

	float trueWidth = dummy_.getGlobalBounds().width + dummy_.getGlobalBounds().left;
	float trueHeight = dummy_.getGlobalBounds().height + dummy_.getGlobalBounds().top;

	if (lastX_ + trueWidth > x_ + w_) {
		returnLine();
	}

	addComponant(lastX_, lastY_ - dummy_.getCharacterSize(), trueWidth, trueHeight, cur_);

	lastX_ += trueWidth;
	index_ = lastIndex_;

	lineMaxSize_ = size_ > lineMaxSize_ ? size_ : lineMaxSize_;

	cur_ = "";
}

void UIRichText::returnLine()
{
	lastY_ += lineMaxSize_ + RICHTEXT_INTERLINE_SIZE;
	lastX_ = x_;
	lineMaxSize_ = 0;
}
