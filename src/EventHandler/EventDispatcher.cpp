#include "EventDispatcher.h"

#include <iostream>

void EventDispatcher::handle(Event* ev)
{
	for (auto evr : eventRecievers_) {
		EventResponse* response = nullptr;
		evr->recieve(ev, &response);
		if (response != nullptr) {
			response->execute();
			if(response->deletable())
				delete response;
		}
	}
}

void EventDispatcher::subscribe(EventReciever* service)
{
	eventRecievers_.push_back(service);
}

void EventDispatcher::unsubscribe(EventReciever* service)
{
	eventRecievers_.erase(std::find(eventRecievers_.begin(), eventRecievers_.end(), service));
}
