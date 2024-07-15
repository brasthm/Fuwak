#ifndef FUWAK_COMBAT_MODEL_H
#define FUWAK_COMBAT_MODEL_H

#include "../EventHandler/EventReciever.h"

#include "Combat/Map.h"
#include "../Displayer/CombatDisplayer.h"

class CombatModel : public EventReciever
{
public:
	CombatModel(EventDispatcher* ed);
	~CombatModel();

	void render(CombatDisplayer* combatDisplayer);

	void recieve(KeyboardPressEvent* ev, EventResponse** rep) override {};
	void recieve(KeyboardHoldEvent* ev, EventResponse** rep) override {};
	void recieve(MouseMoveEvent* ev, EventResponse** rep) override;
	void recieve(MouseHoverEvent* ev, EventResponse** rep) override {};
	void recieve(MouseRightClickEvent* ev, EventResponse** rep) override {};
	void recieve(MouseLeftClickEvent* ev, EventResponse** rep) override {};
	void recieve(MouseRightDragEvent* ev, EventResponse** rep) override {};
	void recieve(MouseLeftDragEvent* ev, EventResponse** rep) override;
	void recieve(MouseRightDragReleaseEvent* ev, EventResponse** rep) override {};
	void recieve(MouseLeftDragReleaseEvent* ev, EventResponse** rep) override;
	void recieve(MouseWheelScrollEvent* ev, EventResponse** rep) override;
	void recieve(MouseMiddleClickEvent* ev, EventResponse** rep) override {};

private:
	Map *map_;
};

#endif

