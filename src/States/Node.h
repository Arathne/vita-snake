#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		virtual ~Node (void) {};
		virtual Node* process (void) = 0;
};

#endif
