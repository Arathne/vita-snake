#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "Node.h"
#include "Menu.h"

class StateManager
{
	public:
		~StateManager (void);
		
		static void process (void);

	private:
		static StateManager instance;
		StateManager (void);

		Node* state_;
};

#endif
