#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "../Rectangle.h"
#include "../Log.h"

#include "BodyUp.h"
#include "BodyDown.h"
#include "BodyRight.h"
#include "BodyLeft.h"

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
		
		DIRECTION opposite (DIRECTION direction);
		DIRECTION facing_;
		DIRECTION next_;
		
		Body* head_;
		Rectangle tracker_;
		std::vector<Body*> body_;
		float speed_;
		int counter_;
};

#endif
