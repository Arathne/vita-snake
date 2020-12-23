#include "Snake.h"

#define SQUARE 32
#define GAP 3

Snake::Snake (void):
	facing_(NONE),
	next_(facing_),
	head_(nullptr),
	tracker_(Rectangle((960/2)-(SQUARE/2), (544/2)-(SQUARE/2), SQUARE, SQUARE)),
	speed_(4),
	counter_(0),
	tail_(false),
	max_length_(300)
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
		
			if (offset > 0 && head_ != nullptr)
				head_ -> backward(tracker_, offset);
		}
		
		Snake::changeHead();
		counter_ = 0;
	}
	
	Snake::moveTail();
	
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
		
		head_ = factory_.build(next_, tracker_);
		head_ -> setColor(0, 255, 0);
		
		facing_ = next_;
		tail_ = true;
	}
}

void Snake::direction (DIRECTION input) 
{
	if (facing_ != input && next_ != input && opposite(facing_) != input)
	{
		next_ = input;
	}
}

void Snake::moveTail (void)
{
	if (Snake::getLength() > max_length_)
	{
		int remove = speed_;
		
		for (auto it = body_.begin(); it != body_.end(); it++)
		{
			(*it) -> reduce(remove);
			int length = (*it) -> getLength();
			
			if (length <= 0) {
				remove += length;
				body_.erase(it--);
			}
			else {
				length = (*it) -> getLength();
				if (length <= SQUARE) {
					body_.erase(it--);
				}			
				
				remove = 0;
				break;
			}
		}
		
		if (remove > 0) {
			int length = head_ -> getLength();
			
			if (length - remove < 300)
				head_ -> reduce(length - 300);
			else
				head_ -> reduce(remove);
		}
	}
}

int Snake::getLength (void)
{
	if (head_ == nullptr)
		return 0;

	int length = head_ -> getLength();

	for (auto it = body_.begin(); it != body_.end(); it++)
	{
		length += (*it) -> getLength();
	}
	
	Log::add(length);
	return length;
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
