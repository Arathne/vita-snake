#include "Snake.h"

#define SQUARE 32
#define GAP 3

Snake::Snake (void):
	facing_(NONE),
	next_(facing_),
	head_(nullptr),
	tracker_(Rectangle((960/2)-(SQUARE/2), (544/2)-(SQUARE/2), SQUARE, SQUARE)),
	speed_(4),
	counter_(0)
{
	tracker_.setColor(255, 0, 0);
	
	for (int i = 0; i < 7; i++) // prevent lag spikes when starting
	{
		Log::add("-");
	}
}

Snake::~Snake (void) 
{
	if (head_ != nullptr)
		delete head_;

	for (auto it = body_.begin(); it != body_.end(); it++ )
	{
		delete *it;
	}
}

void Snake::update (void)
{
	if (counter_ * speed_ >= SQUARE + GAP)
	{
		if (facing_ != NONE)
		{
			float offset = (counter_ * speed_) - (SQUARE + GAP);
			Log::add(offset);
		
			if (offset > 0 && head_ != nullptr)
				head_ -> backward(tracker_, offset);
		}
		
		Snake::changeHead();
		
		counter_ = 0;
	}
	
	if (head_ != nullptr)
		head_ -> forward(tracker_, speed_);

	counter_++;
}

void Snake::changeHead (void)
{
	if (facing_ != next_)
	{
		if (head_ != nullptr)
			body_.push_back(head_);
		
		if (next_ == UP)
			head_ = new BodyUp(tracker_);
		else if (next_ == DOWN)
			head_ = new BodyDown(tracker_);
		else if (next_ == LEFT)
			head_ = new BodyLeft(tracker_);
		else if (next_ == RIGHT)
			head_ = new BodyRight(tracker_);
		
		head_ -> setColor(0, 255, 0);
		facing_ = next_;
	}
}

void Snake::direction (DIRECTION input) 
{
	if (facing_ != input && next_ != input && Snake::opposite(facing_) != input)
	{
		next_ = input;
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
		(*it) -> draw();
	}
	
	if (head_ != nullptr)
		head_ -> draw();
	
	tracker_.draw();
}
