#ifndef BODY_H
#define BODY_H

#include "../Rectangle.h"

/* NOTE: moving a body part of the snake is not as simple as changing x and y axis.
 *       width and height also need to be changed based on the direction it is going
 *       which is why polymorphism is used.
*/

class Body
{
	public:
		virtual ~Body (void) {};

		virtual void forward (Rectangle & tracker, float speed) = 0;
		virtual void backward (Rectangle & tracker, float speed) = 0;
		virtual void draw (void) = 0;
		virtual void setColor (int r, int g, int b) = 0;
		virtual void reduce (float speed) = 0;
		virtual float getLength (void) = 0;
};

#endif
