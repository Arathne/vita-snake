#include "snake.h"

#define DEFAULT_SIZE 50

Snake::Snake (void):
	head_(),
	size_ (DEFAULT_SIZE)
{}

Snake::Snake (int x, int y):
	head_ (x, y),
	size_ (DEFAULT_SIZE)
{}

void Snake::setSize( int size )
{
	if (size > 0);
		size_ = size;
}

void Snake::draw (SDL_Renderer & renderer)
{
	SDL_Rect square;
	square.x = head_.x;
	square.y = head_.y;
	square.w = size_;
	square.h = size_;

	SDL_RenderFillRect( &renderer, &square );
}
