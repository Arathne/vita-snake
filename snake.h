#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include "vector.h"

class Snake
{
	public:
		Snake (void);
		Snake (int x, int y);
		
		void setSize (int size);

		void draw (SDL_Renderer & renderer);
	
	private:
		Vector2d head_;
		int size_;
};

#endif
