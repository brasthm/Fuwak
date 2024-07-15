#include "EventHandler.h"
#include "../System/Utils.h"

#include <iostream>



void EventHandler::setNext(EventHandler* handler)
{
	next_ = handler;
}

void EventHandler::handle(Event* ev)
{
	if (next_ != nullptr && !ev->processed())
		next_->handle(ev);
}



