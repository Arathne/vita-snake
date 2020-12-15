#ifndef GAME_H
#define GAME_H

#include "Node.h"
#include "../Snake.h"

class Game : public Node
{
	public:
		Game (void);
		~Game (void);

		Node* process (void);
	
	private:
		void input (void);

		Snake snake_;
};

#endif
