#include "snake.h"

#define DEFAULT_SIZE 50
#define DEFAULT_SPEED 1

Snake::Snake (void):
	color_({255,0,0,255}),
	direction_ (1, 0),
	speed_ (DEFAULT_SPEED),
	size_ (DEFAULT_SIZE),
	head_ ()
{}

Snake::Snake (int x, int y, SDL_Color color):
	color_(color),
	direction_ (1, 0),
	speed_ (DEFAULT_SPEED),
	size_ (DEFAULT_SIZE),
	head_ (x, y)
{}

void Snake::setSize (int size)
{
	if (size > 0);
		size_ = size;
}

void Snake::move (void)
{
	head_ += direction_ * speed_;	
}

void Snake::draw (SDL_Renderer & renderer)
{
	SDL_Rect square;
	square.x = head_.x;
	square.y = head_.y;
	square.w = size_;
	square.h = size_;

	SDL_SetRenderDrawColor( &renderer, color_.r, color_.g, color_.b, color_.a );
	SDL_RenderFillRect( &renderer, &square );
}
