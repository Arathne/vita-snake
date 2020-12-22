#ifndef BODY_DOWN_H
#define BODY_DOWN_H

#include "Body.h"
#include "../Rectangle.h"

class BodyDown : public Rectangle, public Body
{
	public:
		BodyDown (void);
		BodyDown (const Rectangle & rect);
		~BodyDown (void);

		void forward (Rectangle & tracker, float speed);
		void backward (Rectangle & tracker, float speed);
		void draw (void);
		void setColor (int r, int g, int b);
};

#endif