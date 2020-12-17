#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "Rectangle.h"
#include "Log.h"

enum DIRECTION { UP, DOWN, LEFT, RIGHT, NONE };

class Snake
{
	public:
		Snake (void);
		~Snake (void);
		
		void update (void);
		void direction (DIRECTION input);
		void draw (void);

	private:
		void changeHead (void);

		DIRECTION facing_;
		DIRECTION next_;
		Rectangle head_;
		Rectangle tracker_;
		std::vector<Rectangle> body_;
		float speed_;
		int counter_;
};

#endif
