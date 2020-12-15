#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "Rectangle.h"

enum DIRECTION { UP, DOWN, LEFT, RIGHT, NONE };

class Snake
{
	public:
		Snake (void);
		~Snake (void);
		
		void update (DIRECTION input);
		void draw (void);

	private:
		void moveHead (void);

		DIRECTION facing_;
		Rectangle head_;
		Rectangle tracker_;
		std::vector<Rectangle> body_;
		float speed_;
};

#endif
