#include "Snake.h"

#define SQUARE 30
#define GAP 2

Snake::Snake (void):
	facing_(NONE),
	next_(facing_),
	head_(Rectangle((960/2)-(SQUARE/2), (544/2)-(SQUARE/2), SQUARE, SQUARE)),
	tracker_(head_),
	speed_(1),
	counter_(0)
{
	tracker_.setColor(255, 0, 0);
}

Snake::~Snake (void) {}

void Snake::update (void)
{
	if (counter_ > SQUARE + GAP)
	{
		counter_ = 0;
		Snake::changeHead();
	}
	
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
	
	counter_++;
}

void Snake::direction (DIRECTION input) 
{
	if (facing_ != input && next_ != input && Snake::opposite(facing_) != input)
	{
		next_ = input;
	}
}

void Snake::changeHead (void)
{
	if (facing_ != next_)
	{
		body_.push_back(head_);
		head_ = tracker_;
		head_.setColor(0, 255, 0);
		facing_ = next_;
	}
}

DIRECTION Snake::opposite (DIRECTION direction)
{
	DIRECTION opp = NONE;

	if (direction == UP)
		opp = DOWN;
	else if (direction == DOWN)
		opp = UP;
	else if (direction == LEFT)
		opp = RIGHT;
	else if (direction == RIGHT)
		opp = LEFT;

	return opp;
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
