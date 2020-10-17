#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include "vector.h"

class Snake
{
	public:
		Snake (void);
		Snake (int x, int y, SDL_Color color);
		
		void setSize (int size);

		void draw (SDL_Renderer & renderer);
	
	private:
		SDL_Color color_;
		
		int size_;
		
		Vector2d head_;
};

#endif
