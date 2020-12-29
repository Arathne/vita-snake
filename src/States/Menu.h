#ifndef MENU_H
#define MENU_H

#include "Node.h"
#include "Game.h"
#include "../Text.h"

class Menu : public Node
{
	public:
		Menu (void);
		~Menu (void);

		Node* process (void);
	
	private:
		void input (void);
		void drawOptions (void);

		int selected_;
		
		Text title_;
		Text play_;
		Text options_;
		Text highscores_;
};

#endif
