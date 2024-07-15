#include "UIHorizontalStacker.h"

static constexpr float UI_CONTAINER_HORIZONTAL_MARGIN = 5.f;

void UIHorizontalStacker::add(UIComponant* comp)
{
	if (content_.size() != 0)
		comp->move(content_.back()->getCoords().left + content_.back()->getCoords().width + UI_CONTAINER_HORIZONTAL_MARGIN,
			 y_);
	else
		comp->move(x_, y_);

	sf::FloatRect box = comp->getCoords();

	comp->resize(box.width, h_);

	UIContainer::add(comp);

	float newMaxWidth = box.left + box.width;
	if (w_ + x_ < newMaxWidth)
		resize(newMaxWidth - x_, h_);

	float newMaxHeight = box.top + box.height;
	if (h_ + y_ < newMaxHeight)
		resize(w_, newMaxHeight - y_);
}

void UIHorizontalStacker::resize(float w, float h)
{
	UIComponant::resize(w, h);

	for (auto c : content_) {
		c->resize(-1, h);
	}
}
