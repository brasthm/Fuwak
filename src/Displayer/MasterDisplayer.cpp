#include "MasterDisplayer.h"

MasterDisplayer::MasterDisplayer()
{
	displayers_.push_back(new CombatDisplayer());
}

MasterDisplayer::~MasterDisplayer()
{
}
