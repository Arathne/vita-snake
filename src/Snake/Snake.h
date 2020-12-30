#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "../Rectangle.h"

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
			
		bool collided (void) const;
		bool collided (const Rectangle & rectangle) const;
		bool screenCollision (void) const;

		void grow (void);

	private:
		void changeHead (void);
		void moveTail (void);
		int getLength (void);
		bool collided (const Body & body, const Rectangle & rect) const;

		DIRECTION facing_;
		DIRECTION next_;
		
		BodyFactory factory_;

		Body* head_;
		Rectangle tracker_;
		std::vector<Body*> body_;
		float speed_;
		int counter_;
		bool tail_;
		int max_length_;
};

#endif
