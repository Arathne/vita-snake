#ifndef MENU_H
#define MENU_H

#include "Node.h"

class Menu : public Node
{
	public:
		Menu (void);
		~Menu (void);

		Node* process (void);
	
	private:
		void spacing (Text & current, Text & previous);
		
		Text title_;
		Text play_;
		Text options_;
		Text highscores_;
};

#endif
