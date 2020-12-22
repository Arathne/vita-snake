#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "../Rectangle.h"
#include "../Log.h"

#include "DirectionEnum.h"
#include "BodyFactory.h"

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
		
		BodyFactory factory_;

		Body* head_;
		Rectangle tracker_;
		std::vector<Body*> body_;
		float speed_;
		int counter_;
};

#endif
