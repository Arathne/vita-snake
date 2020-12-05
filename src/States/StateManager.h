#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "Node.h"
#include "Menu.h"

class StateManager
{
	public:
		static void reset (void);
		static void process (void);

	private:
		static GameRenderer renderer_;
		static Node* state_;
};

#endif
