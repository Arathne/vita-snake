#ifndef BODY_H
#define BODY_H

#include "../Rectangle.h"

class Body
{
	public:
		virtual ~Body (void) {};

		virtual void forward (Rectangle & tracker, float speed) = 0;
		virtual void backward (Rectangle & tracker, float offset) = 0;
		virtual void draw (void) = 0;
		virtual void setColor (int r, int g, int b) = 0;
};

#endif
