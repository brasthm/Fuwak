#ifndef FUWAK_EVENTDISPATCHER_H
#define FUWAK_EVENTDISPATCHER_H

#include "EventHandler.h"
#include "EventReciever.h"

#include <vector>

class EventDispatcher : public EventHandler {
public:
	void handle(Event* ev) override;
	void subscribe(EventReciever* servive);
	void unsubscribe(EventReciever* servive);
protected:
	std::vector<EventReciever*> eventRecievers_;
};

#endif
