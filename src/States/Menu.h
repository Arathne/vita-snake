#ifndef MENU_H
#define MENU_H

#include "Node.h"
#include "Game.h"
#include "../Text.h"
#include "../UI/Selector.h"
#include "../Snake/Snake.h"

class Menu : public Node
{
	public:
		Menu (void);
		~Menu (void);

		Node* process (void);
		const char* getName (void) const;
	
	private:
		void input (void);
		void snake (void);
		void draw (void);

		int selected_;
		Text title_;
		std::vector<Option*> options_;
		Snake* snake_;
		Text signature_;
};

#endif
