#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "../Input.h"

class Node
{
	public:
		virtual ~Node (void) {};
		
		virtual Node* process (void) = 0;
		virtual const char* getName (void) const = 0;
};

#endif
