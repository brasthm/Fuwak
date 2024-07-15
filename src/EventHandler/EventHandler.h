#pragma once

#include "SFML/Graphics.hpp"

#include "Event.h"


class EventResponse {
public:
	EventResponse() : deletable_(true), caller_(0) {};
	virtual void execute() = 0;
	bool deletable() { return deletable_; };
	void setDeletable(bool val) { deletable_ = val; };
	void setCaller(void* caller) { caller_ = caller; };
private :
	bool deletable_;
protected:
	void* caller_;
};

class EventHandler {
private:
	EventHandler* next_;

public:
	EventHandler() { next_ = nullptr; };
	virtual void setNext(EventHandler* handler);
	virtual void handle(Event* ev);
};


