#include "StateManager.h"

Node* StateManager::state_ = nullptr;

void StateManager::process (void)
{
	if (state_ == nullptr)
		state_ = new Menu();

	Node* current = state_;
	state_ = current -> process();

	if (current != state_)
		delete current;
}

void StateManager::reset (void)
{
	if (state_ != nullptr)
		delete state_;
}
