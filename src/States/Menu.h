#ifndef MENU_H
#define MENU_H

#include "Node.h"
#include "Game.h"
#include "../Text.h"
#include "../UI/Selector.h"

class Menu : public Node
{
	public:
		Menu (void);
		~Menu (void);

		Node* process (void);
	
	private:
		void input (void);
		void draw (void);

		int selected_;
		Text title_;
		std::vector<Option*> options_;
};

#endif
