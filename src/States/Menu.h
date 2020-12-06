#ifndef MENU_H
#define MENU_H

#include "Node.h"
#include "../Text.h"

class Menu : public Node
{
	public:
		Menu (void);
		~Menu (void);

		Node* process (void);
	
	private:
		Text* text_;
};

#endif
