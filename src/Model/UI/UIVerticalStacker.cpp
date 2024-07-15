#include "UIVerticalStacker.h"

static constexpr float UI_CONTAINER_VERTICAL_MARGIN = 5.f;


void UIVerticalStacker::add(UIComponant* comp)
{
	if (content_.size() != 0)
		comp->move(x_,
				   content_.back()->getCoords().top + content_.back()->getCoords().height + UI_CONTAINER_VERTICAL_MARGIN);
	else
		comp->move(x_,
				   y_);

	sf::FloatRect box = comp->getCoords();

	comp->resize(w_, box.height);

	UIContainer::add(comp);

	float newMaxHeight = box.top + box.height;
	if (h_ + y_ < newMaxHeight)
		resize(w_, newMaxHeight - y_);

	float newMaxWidth = box.left + box.width;
	if (w_ + x_ < newMaxWidth)
		resize(newMaxWidth - x_, h_);
}

void UIVerticalStacker::resize(float w, float h)
{
	UIComponant::resize(w, h);

	for (auto c : content_) {
		c->resize(w, -1);
	}
	
}
