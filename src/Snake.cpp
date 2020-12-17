#include "Snake.h"

#define SQUARE 30

Snake::Snake (void):
	facing_(NONE),
	head_(Rectangle((960/2)-(SQUARE/2), (544/2)-(SQUARE/2), SQUARE, SQUARE)),
	tracker_(head_),
	speed_(1)
{
	tracker_.setColor(255, 0, 0);
}

Snake::~Snake (void) {}

void Snake::direction (DIRECTION input) 
{
	if (input != facing_)
	{
		body_.push_back(head_);
		head_ = tracker_;
		head_.setColor(0, 255, 0);
		facing_ = input;
	}
}

void Snake::update (void)
{
	if (facing_ == UP) 
	{
		tracker_.moveY(-speed_);
		head_.moveY(-speed_);
		head_.addHeight(speed_);
	}
	else if (facing_ == DOWN) 
	{
		tracker_.moveY(speed_);
		head_.addHeight(speed_);
	}
	else if (facing_ == LEFT) 
	{
		tracker_.moveX(-speed_);
		head_.moveX(-speed_);
		head_.addWidth(speed_);
	}
	else if (facing_ == RIGHT) 
	{
		tracker_.moveX(speed_);
		head_.addWidth(speed_);
	}
}

void Snake::draw (void) 
{
	for (auto it = body_.begin(); it != body_.end(); it++)
	{
		(*it).draw();
	}
	
	head_.draw();
	tracker_.draw();
}
