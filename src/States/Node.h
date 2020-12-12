#ifndef NODE_H
#define NODE_H

#include "../GameRenderer.h"
#include "../Log.h"

class Node
{
	public:
		virtual ~Node (void) {};
		virtual Node* process (void) = 0;
};

#endif
