#ifndef GAME_H
#define GAME_H

#include "Node.h"

class Game : public Node
{
	public:
		Game (void);
		~Game (void);

		Node* process (void);
};

#endif
