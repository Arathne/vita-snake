#ifndef NODE_H
#define NODE_H

#include "../Log.h"
#include "../Input.h"

class Node
{
	public:
		virtual ~Node (void) {};
		virtual Node* process (void) = 0;
};

#endif
